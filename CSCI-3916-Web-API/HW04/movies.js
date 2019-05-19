var mongoose = require('mongoose');
var Schema = mongoose.Schema;

mongoose.Promise = global.Promise;

mongoose.connect(process.env.MONGODB_URL, { useNewUrlParser: true } );
mongoose.set('useCreateIndex', true);

var movieSchema  = new Schema({
    Title: {type:String, required:true},
    Year: {type:Date, required:true},
    Genre: {type:String, required:true, enum:["Action", "Adventure", "Comedy", "Drama", "Fantasy", "Horror", "Mystery", "Thriller", "Western"]},
    Actors: {type:[{ActorName:String, CharacterName:String}], required:true},
    ImageURI: {type:String, required: false},
    averageRating: {type:Number, required: false}
});

var Movie = mongoose.model('Movie', movieSchema);

module.exports = Movie;