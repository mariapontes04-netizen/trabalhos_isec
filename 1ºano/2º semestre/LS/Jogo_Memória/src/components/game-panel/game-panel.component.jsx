import React, { useEffect, useState } from "react";
import "./game-panel.css";
import {Card} from "../index";

function GamePanel({cards, selectedLevel, gameStarted, onGameStart, onPoints}){
    let gameClass =
        selectedLevel=== "1"
        ?""
        :selectedLevel === "2"
        ? "intermedio"
        : "avancado";
    
    const [matchedCards, setMatchedCards] =useState([]);
    const processMatchingCards=()=>{
        const [card1, card2] = flippedCards;
        const cardsAreEqual = card1===card2;1

        if(cardsAreEqual){
            setTimeout(()=>{
                setMatchedCards((previousState)=>[...previousState,card1,card2]);
                onPoints(true);
            },500);
        }
        else{
            setTimeout(()=>{
                setMatchedCards((previousState)=>[...previousState]);
                onPoints(false);
            },500);
        }
        flippedCards=[];
    };

    let flippedCards=[];
    const [matchedCards, setMatchedCards]=useState([]);
    const handleFlipeedCards=(card)=>{
        flippedCards=[...flippedCards,card]
        if(flippedCards.length===2){
            //console.log(...processMatchingCards);
        }
    }

    useEffect(() => {
        if (matchedCards.length === cards.length && gameStarted)
        {
        onGameStart();
        }
       }, [matchedCards, cards, gameStarted, onGameStart]);

    useEffect(()=>{
        if(!gameStarted){
            setMatchedCards([]);
        }
    }, [gameStarted]);

    return(
        <section id="panel-game">
            <h3 className="sr-only">Peças do Jogo</h3>
            <div id="game" className={gameClass}>
              
                {cards.map((ele)=>(
                    <Card 
                        key={ele.id} 
                        name={ele.name} 
                        gameStarted={gameStarted}
                        onFlippedCards={handleFlipeedCards}
                        matchedCards={matchedCards} />
                ))}
            </div>
        </section>
    )
}

export default GamePanel;