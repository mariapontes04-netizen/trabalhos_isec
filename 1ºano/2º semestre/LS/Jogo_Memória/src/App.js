import { useState } from "react";
import "./assets/styles/App.css";
import { ControlPanel, Footer, Header,GamePanel, GameOverModal} from "./components";
import { CARDS_LOGOS } from "./constants";
import {shuffleArray} from "./helpers";

function App() {
  const [gameStarted, setGameStarted]=useState(false);
  const [selectedLevel, setSelectedLevel]=useState("0");
  const [cards, setCards]=useState([]);
  const[totalPoints,setTotalPoints]=useState(0);
  let timer;

  const handlerTimerApp=(t)=>{
    timer=t;
    //console.log(timer);
  }
  
  const createPanel=(level)=>{
    let numOfCardPairs;
    switch(level){
      case '1': numOfCardPairs=3; break;
      case '2': numOfCardPairs=6; break;
      case '3': numOfCardPairs=10; break;
      default: numOfCardPairs=0; break;
    }
    let initialCards=shuffleArray(CARDS_LOGOS);
    initialCards=initialCards.slice(0,numOfCardPairs);

    const doubleCardsObject=[];
    initialCards.forEach((card)=>{
      doubleCardsObject.push({id: card, name: card});
      doubleCardsObject.push({id: `${card}-clone`, name: card});
    });
    const doubleShuffledCardsObjects=shuffleArray(doubleCardsObject);
    setCards([...doubleShuffledCardsObjects]);
  }

  const handleGameStart=()=>{
    if(gameStarted){
      setGameStarted(false);
    }
    else{
      setGameStarted(true);
      createPanel(selectedLevel);
      setTotalPoints(0);
    }
  }

  const handleLevelChange=(event)=>{
    const value=event.currentTarget.value;
    setSelectedLevel(value);
    createPanel(value);
  }

  const handlePoints = (operacaoSoma = true) => {
    let pointsSum = totalPoints;
    if (operacaoSoma)
    {
      pointsSum += timer * (cards.length / 2);
    }
    else
    {
      pointsSum < 5 ? (pointsSum = 0) : (pointsSum -= 5);
    }
    setTotalPoints(pointsSum);
  };

  return (
    <div id="container">
      <Header />
      <main className="main-content">
        <ControlPanel gameStarted={gameStarted} 
                      onGameStart={handleGameStart} 
                      selectedLevel={selectedLevel}
                      onLevelChange={handleLevelChange}
                      onTimerApp={handlerTimerApp}
                      onPoints={handlePoints}
                      totalPoints={totalPoints}/>
        <GamePanel cards={cards} selectedLevel={selectedLevel}/>
      </main>
      <GameOverModal isOpen={isGameOverModalOpen}
                      handleClose={handleGameOverModelClose}
                      points={totalPoints}/>
      <Footer />
    </div>
  );
}

export default App;
