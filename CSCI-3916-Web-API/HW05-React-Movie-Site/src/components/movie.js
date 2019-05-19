import React, { Component }  from 'react';
import {connect} from "react-redux";
import {
    Glyphicon,
    Panel,
    ListGroup,
    ListGroupItem,
    Form,
    FormGroup,
    Col,
    ControlLabel,
    FormControl, Button,
} from 'react-bootstrap'
import { Image } from 'react-bootstrap'
import { withRouter } from "react-router-dom";
import {fetchMovie} from "../actions/movieActions";
import runtimeEnv from "@mars/heroku-js-runtime-env";

class Movie extends Component {

    constructor(props) {
        super(props);
        this.updateDetails = this.updateDetails.bind(this);
        this.reviewSub = this.reviewSub.bind(this);

        this.state = {
            details:{
                review: '',
                rating: 0
            }
        };
    }

    componentDidMount() {
        const {dispatch} = this.props;
        if (this.props.selectedMovie == null)
            dispatch(fetchMovie(this.props.movieId));
    }

    updateDetails(event){
        let updateDetails = Object.assign({}, this.state.details);

        updateDetails[event.target.id] = event.target.value;
        this.setState({
            details: updateDetails
        });
    }

    reviewSub() {
        const env = runtimeEnv();

        var json = {
            Review: this.state.details.review,
            Rating: this.state.details.rating,
            Movie_ID: this.props.movieId
        };

        return fetch(`${env.REACT_APP_API_URL}/reviews`, {
            method: 'POST',
            headers: {
                'Accept': 'application/json',
                'Content-Type': 'application/json',
                'Authorization': localStorage.getItem('token')
            },
            body: JSON.stringify(json),
            mode: 'cors'})
            .then( (response) => {
                if (!response.ok) {
                    throw Error(response.statusText);
                }
                return response.json();
            })
            .then( (res) => {
                window.location.reload();
            })
            .catch( (e) => console.log(e) );

    }

    render() {
        const ActorInfo = ({Actors}) => {
            return Actors.map((actor, i) =>
                <p key={i}>
                    <b>{actor.ActorName}</b> {actor.CharacterName}
                </p>
            );
        };

        const ReviewInfo = ({Reviews}) => {
            return Reviews.map((review, i) =>
                <p key={i}>
                    <b>{review.Name}</b> {review.Review}
                    <Glyphicon glyph={'star'} /> {review.Rating}
                </p>
            );
        };

        const DetailInfo = ({currentMovie}) => {
            if (!currentMovie) { // evaluates to true if currentMovie is null
                return <div>Loading...</div>;
            }
            return (
                <Panel>
                    <Panel.Heading>Movie Detail</Panel.Heading>
                    <Panel.Body><Image className="image" src={currentMovie.ImageURI} thumbnail /></Panel.Body>
                    <ListGroup>
                        <ListGroupItem>{currentMovie.Title}</ListGroupItem>
                        <ListGroupItem><ActorInfo Actors={currentMovie.Actors} /></ListGroupItem>
                        <ListGroupItem><h4><Glyphicon glyph={'star'} /> {currentMovie.averageRating} </h4></ListGroupItem>
                    </ListGroup>
                    <Panel.Body><ReviewInfo Reviews={currentMovie.Reviews} /></Panel.Body>

                </Panel>
            );
        };

        return (
            <div>
                <DetailInfo currentMovie={this.props.selectedMovie} />
                <Form horizontal>
                    <FormGroup controlId="review">
                        <Col componentClass={ControlLabel} sm={2}>
                            Review
                        </Col>
                        <Col sm={10}>
                            <FormControl onChange={this.updateDetails} value={this.state.details.review} type="text" placeholder="type review here..." />
                        </Col>
                    </FormGroup>

                    <FormGroup controlId="rating">
                        <Col componentClass={ControlLabel} sm={2}>
                            Rating
                        </Col>
                        <Col sm={10}>
                            <FormControl onChange={this.updateDetails}
                                         value={this.state.details.rating}
                                         type="number" min="1" max="5" />
                        </Col>
                    </FormGroup>

                    <FormGroup>
                        <Col smOffset={2} sm={10}>
                            <Button onClick={this.reviewSub}>Submit</Button>
                        </Col>
                    </FormGroup>
                </Form>

            </div>

        );
    }
}

const mapStateToProps = (state, ownProps) => {
    return {
        selectedMovie: state.movie.selectedMovie,
        movieId: ownProps.match.params.movieId
    }
}

export default withRouter(connect(mapStateToProps)(Movie));