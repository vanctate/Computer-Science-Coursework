var mongoose = require('mongoose');
var Schema = mongoose.Schema;

mongoose.Promise = global.Promise;

mongoose.connect(process.env.MONGODB_URL, { useNewUrlParser: true } );
mongoose.set('useCreateIndex', true);

var reviewSchema  = new Schema({
    Name: {type:String, required:true},
    Review: {type:String, required:true},
    Rating: {type:Number, min: 0, max: 5, required:true},
    Movie_ID: {type:mongoose.Types.ObjectId, required:true}
});

var Review = mongoose.model('Review', reviewSchema);

module.exports = Review;