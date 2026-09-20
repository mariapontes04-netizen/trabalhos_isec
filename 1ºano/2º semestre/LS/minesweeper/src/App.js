import './style/App.css';
import React from "react";
import { useState } from "react";

import ControlPanel from "./components/control-panel/control.panel.component";
import GamePanel from "./components/game-panel/game-panel.component";
import Header from "./components/header/header.component";
import Footer from "./components/footer/footer.component";

function App() {
  const [gameStarted, setGameStarted]=useState(false);
  const [selectedLevel,setSelectedLevel]=useState("0");
  const [win,setWin]=useState(1);
  const handleGameStart = ()=>
  {
    if(gameStarted)
    {setGameStarted(false);
      setWin(1);
    }
    else
    {
      setGameStarted(true)
    }
  }
  const handleLevelChange=(event)=>
  {
    const val= event.currentTarget.value;
    setSelectedLevel(val);
  
  }
  return (
    <div id="container">
      <Header/>
      <ControlPanel 
        gameStarted={gameStarted} 
        onGameStart={handleGameStart}
        selectedLevel={selectedLevel}
        onLevelChange={handleLevelChange}
        win={win}
        calculateScore
      />
      <GamePanel 
        selectedLevel={selectedLevel}
        gameStarted={gameStarted}
        win={win}
        onWin={setWin}
      />
      <Footer/>
    </div>
  );
}

export default App;
