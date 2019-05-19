var express = require('express');
var bodyParser = require('body-parser');
var passport = require('passport');
var authJwtController = require('./auth_jwt');
var User = require('./Users');
var jwt = require('jsonwebtoken');

var app = express();
module.exports = app; // for testing
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.use(passport.initialize());
var router = express.Router();

let Movie = require("./Movies");//makes the Movie obj work from the Movies.js exports line

router.route('/postjwt')
    .post(authJwtController.isAuthenticated, function (req, res) {
            console.log(req.body);
            res = res.status(200);
            if (req.get('Content-Type')) {
                console.log("Content-Type: " + req.get('Content-Type'));
                res = res.type(req.get('Content-Type'));
            }
            res.send(req.body);
        }
    );

router.route('/users/:userId')
    .get(authJwtController.isAuthenticated, function (req, res) {
        var id = req.params.userId;
        User.findById(id, function(err, user) {
            if (err) res.send(err);

            var userJson = JSON.stringify(user);
            // return that user
            res.json(user);
        });
    });

router.route('/users')
    .get(authJwtController.isAuthenticated, function (req, res) {
        User.find(function (err, users) {
            if (err) res.send(err);
            // return the users
            res.json(users);
        });
    });

router.post('/signup', function(req, res) {
    if (!req.body.username || !req.body.password) {
        res.json({success: false, message: 'Please pass username and password.'});
    }
    else {
        var user = new User();
        user.name = req.body.name;
        user.username = req.body.username;
        user.password = req.body.password;
        // save the user
        user.save(function(err) {
            if (err) {
                // duplicate entry
                if (err.code === 11000)
                    return res.json({ success: false, message: 'A user with that username already exists. '});
                else
                    return res.send(err);
            }

            res.json({ success: true, message: 'User created!' });
        });
    }
});

router.post('/signin', function(req, res) {
    var userNew = new User();
    userNew.name = req.body.name;
    userNew.username = req.body.username;
    userNew.password = req.body.password;

    User.findOne({ username: userNew.username }).select('name username password').exec(function(err, user) {
        if (err) res.send(err);

        user.comparePassword(userNew.password, function(isMatch){
            if (isMatch) {
                var userToken = {id: user._id, username: user.username};
                var token = jwt.sign(userToken, process.env.SECRET_KEY);
                res.json({success: true, token: 'JWT ' + token});
            }
            else {
                res.status(401).send({success: false, message: 'Authentication failed.'});
            }
        });


    });
});



//need to make sure authHwtController.isAuthenticated is the one used for all the different routes
router.route("/movies")
    .post(authJwtController.isAuthenticated,function(req, res)  //create a new movie
    {//in the function params cannot double up two res's, all four must be different to work
        Movie.findOne({Title: req.body.Title}, function(err)//for whatever reason this only allows one movie into the db at a time
        {
            if (err)
            {
                res.status(400);
            }
            else if(req.body.ActorsAndCharacters.length < 3)
            {
                res.json({message: "You must have at least 3 actors and characters per movie!"});
            }
            else if (req.data !== 0) {
                let newmovie = new Movie;
                newmovie.Title = req.body.Title;
                newmovie.ReleaseDate = req.body.ReleaseDate;
                newmovie.Genre = req.body.Genre;
                newmovie.ActorsAndCharacters = req.body.ActorsAndCharacters;

                //console.log(newmovie);
                newmovie.save(function (err)
                {
                    if (err)
                    {
                       res.json({message: err});
                    }
                    else
                    {
                        res.json({status: 200, success: true, message: "The movie " + req.body.Title + " has been successfully saved!"});
                    }
                });
            }
        });
    })
    .get(authJwtController.isAuthenticated,function(req,res)//search for a movie
    {
        Movie.find({Title: req.body.Title}, function(err, data)
        {
            if (err)//if there is any err, print the err and response message
            {
                res.json(err);
                res.json({message: "There was an issue trying to find your movie"})
            }
            else if (data.length === 0)//if there is no return of data the movie was not found
            {   //don't think this is correct
                res.json({message: "The Movie " + req.body.Title + " was not found"});
            }
            else//if there is no error and there is data which means we found the movie due to the find function
            {
                res.json({status: 200, message: "The movie with " + req.body.Title + " was found!"});
            }
        })
        //res.json({ status: 200, message: "Movie Found", headers: req.headers, query: req.query, env: process.env.SECRET_KEY});
        //just use the find function from above and print out if there is a record that is found.
    })
    .put(authJwtController.isAuthenticated,function(req,res)//get a movie/search for one ish...
    {
        Movie.findOneAndUpdate({Title: req.body.Title},//originally had .Title but it didn't work with the function(doc)
        {
            Title: req.body.Title,
            ReleaseDate: req.body.ReleaseDate,
            Genre: req.body.Genre,
            ActorsAndCharacters: req.body.ActorsAndCharacters//becasue ActorsAndCharacters is the parent schema for the three actors and characters
        },function(err, doc, data)//originally had (err and data) but I needed doc becasuse I had to switch to use Search to have Heroku work
            {//because Heroku will not work using findOneAndUpdate unless you have .Search and doc, as opposed to .Search and data.length
                if(err)
                {
                    res.json({message: err});
                    res.json({message: "There was an issue trying to update your movie."})
                }
                else if(doc === 0)
                {
                    res.json({message: "Sorry the movie wanted to update was not found in the data base."});
                }
                else
                {
                    res.json({status: 200, message: "The Movie " + req.body.Title + " has been updated!!"});

                }

            });
        //res.json({ status: 200, message: "Movie Found", headers: req.headers, query: req.query, env: process.env.SECRET_KEY});
        //just use the find function from above and print out if there is a record that is found.
    })
    .delete(authJwtController.isAuthenticated, function(req, res)//delete a movie
    {
        Movie.findOneAndDelete({Title: req.body.Title}, function(err, data)//got this code from the get request method
        {
            if (err)
            {
                res.json(err);
                res.json({message: "There was an issue trying to find your movie"})
            }
            else if (data.length === null)
            {   //don't think this is correct
                res.json({message: "The Movie " + req.body.Title + " was not found"});
            }
            else//if there is no error and the movie is not found
            {
                res.json({message: "The movie with " + req.body.Title + " was deleted!"});
            }
        })
    });

router.all('*', function(req, res)  //if there is a response that the server has no way to handle.
{
    res.json({error: "Unsupported HTTP Method"})
});

app.use('/', router);
app.listen(process.env.PORT || 8080);

module.exports = app;

//need to connect to mongoose some how here
/*mongoose.connect(mongoDB, { useNewUrlParser: true },
    {
        //check if there is an error
    }

);
*/