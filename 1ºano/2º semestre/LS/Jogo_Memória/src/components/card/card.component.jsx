import React from "react";
import "./card.css";

import{PLACEHOLDER_CARD_PATH} from "../../constants";
import{PLACEHOLDER_CARDBACK_PATH} from "../../constants";


function Card(props){
    let cardFrontClass=matched ? " grayscale" : "";
    let matchedClass=matched ? " inactive" : "";

    useEffect(() => {
        const isMatchedCard = props.matchedCards.filter((logoName) => logoName===props.name).length > 0;
        setFlipped(isMatchedCard);
        setMatched(isMatchedCard);
        }, [props.matchedCards, props.name]);   

        return(
            <div className={card ${flippedCalss} ${matchedClass}} data-logo={name}>
                <img src={PLACEHOLDER_CARDBACK_PATH}
                    className="card-back" alt="Back"
                    onClick={()=>{if(gameStarted)
                                    setFlipped(true);
                                    onFlipedCards(true);
                    }} />
                <img src={${PLACEHOLDER_CARD_PATH}${card.name}.png}
                    className={card-front ${cardFrontClass}}/>
            </div>
        )    
}

export default Card;