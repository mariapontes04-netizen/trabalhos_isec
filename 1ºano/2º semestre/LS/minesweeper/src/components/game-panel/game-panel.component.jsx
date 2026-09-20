import React, { useState, useEffect } from "react";
import "./game-panel.css";
import Plot from "../plot/plot.component";
import {
  TABLE_BASICO,
  BOMBAS_BASICO,
  TABLE_INTERMEDIO,
  BOMBAS_INTERMEDIO,
  TABLE_AVANCADO,
  BOMBAS_AVANCADO
} from "../../constants";

function GamePanel(props) {
  const { selectedLevel, gameStarted,onWin,win} = props;
  const [plots, setPlots] = useState([]);
  const [bombs, setBombs] = useState([]);
  const [field, setField] = useState({ rows: 0, columns: 0 });
  const[totalPlots,setTotalPlots]=useState();
  useEffect(() => {
    const handleGameSize = () => {
      let fieldSize = { rows: 0, columns: 0 }, bombCount;
      switch (selectedLevel) {
        case "1":
          fieldSize = TABLE_BASICO;
          bombCount = BOMBAS_BASICO;
          break;
        case "2":
          fieldSize = TABLE_INTERMEDIO;
          bombCount = BOMBAS_INTERMEDIO;
          break;
        case "3":
          fieldSize = TABLE_AVANCADO;
          bombCount = BOMBAS_AVANCADO;
          break;
        default:
          break;
      }

      setField(fieldSize);
      
      const bombCoordinates = generateBombCoordinates(fieldSize, bombCount);
      setBombs(bombCoordinates);
      setTotalPlots((field.columns*field.rows)-bombCount)
    };

    if (gameStarted) {
      handleGameSize();
    }
  }, [selectedLevel, gameStarted,field]);

  useEffect(() => {
    const spots = [];
    let i, j;

    for (i = 0; i < field.rows; i++) {
      for (j = 0; j < field.columns; j++) {
        // eslint-disable-next-line no-loop-func
        const isMine = bombs.some(bomb => bomb.row === i && bomb.col === j);
        spots.push({ isMine, row: i, col: j, isClicked: false,isFlag:false,plotAdjacentBombs:0 });
      }
    }
    
    setPlots(spots);
    // console.log(spots);
  }, [bombs, field, gameStarted]);

  const generateBombCoordinates = (field, numBombs) => {
    const rows = field.rows;
    const columns = field.columns;
    const bombCoordinates = [];

    while (bombCoordinates.length < numBombs) {
      const row = Math.floor(Math.random() * rows);
      const col = Math.floor(Math.random() * columns);
      const bomb = { row, col };
      if (!bombCoordinates.some(location => location.row === row && location.col === col)) {
        bombCoordinates.push(bomb);
      }
    }

    return bombCoordinates;
  };
  
  const handlePlotClick = (row, col) => {
    const clickedPlot = plots.find(plot => plot.row === row && plot.col === col);
  
    if (clickedPlot.isMine) {
      // Handle the case when the clicked plot is a bomb
      //alert("Boom! You clicked on a bomb.");
      onWin(3);
      // Optionally, reveal all bombs and end the game
      const updatedPlots = plots.map(plot => {
        if (plot.isMine) {
          return { ...plot, isClicked: true };
        }
        return plot;
      });
      setPlots(updatedPlots);
      return;
    }
  
    revealEmptyCells(row, col);
    checkWin();
  };
  
  const revealEmptyCells = (startRow, startCol) => {
    const queue = [{ row: startRow, col: startCol }];
    const visited = {};
    const updatedPlots = [...plots]; // Clone the plots array for state updates
  
    while (queue.length > 0) {
      const { row, col } = queue.shift();
  
      if (visited[`${row}-${col}`]) continue;
      visited[`${row}-${col}`] = true;
  
      const plotIndex = updatedPlots.findIndex(plot => plot.row === row && plot.col === col);
      if (plotIndex === -1 || updatedPlots[plotIndex].isClicked) continue;
  
      const adjacentBombs = countAdjacentBombs(row, col);
      
      updatedPlots[plotIndex] = { ...updatedPlots[plotIndex], isClicked: true,plotAdjacentBombs:adjacentBombs };
  
      if (adjacentBombs === 0) {
        for (let i = row - 1; i <= row + 1; i++) {
          for (let j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < field.rows && j >= 0 && j < field.columns && !(i === row && j === col)) {
              const adjacentPlotIndex = updatedPlots.findIndex(plot => plot.row === i && plot.col === j);
              if (adjacentPlotIndex !== -1 && !updatedPlots[adjacentPlotIndex].isClicked) {
                queue.push({ row: i, col: j });
              }
            }
          }
        }
      }
    }
  console.log(updatedPlots);
    setPlots(updatedPlots); // Update state once after processing all plots
  };
  
  const countAdjacentBombs = (row, col) => {
    let adjacentBombs = 0;
    for (let i = row - 1; i <= row + 1; i++) {
      for (let j = col - 1; j <= col + 1; j++) {
        if (i >= 0 && i < field.rows && j >= 0 && j < field.columns) {
          if (plots.some(plot => plot.row === i && plot.col === j && plot.isMine)) {
            adjacentBombs++;
          }
        }
      }
    }
    return adjacentBombs;
  };
  
  const checkWin = () => {
    let clickedPlots = 1;
  
    // Count the number of clicked plots
    plots.forEach(plot => {
      if (plot.isClicked) {
        clickedPlots++;
      }
    });
  // console.log(totalPlots);
  // console.log(`Clicked plots: ${clickedPlots}`);
    
    if (clickedPlots === totalPlots) {
      alert("Ganhou");
      onWin(2);
    }
  };
  
  return gameStarted ? (
    <main className="main-content">
      <section id="panel-game">
        <h3 className="sr-only">Peças do Jogo</h3>
        <div id="game" className={selectedLevel === "1" ? "basico" : selectedLevel === "2" ? "intermedio" : "avancado"}>
          {plots.map((ele) => (
            <Plot 
              key={`${ele.row}-${ele.col}`}
              row={ele.row}
              col={ele.col}
              isMine={ele.isMine}
              isClicked={ele.isClicked}
              handlePlotClick={handlePlotClick}
              adjacentBombs={ele.plotAdjacentBombs}
              win={win}
            />
          ))}
        </div>
      </section>
    </main>
  ) : null;
}

export default GamePanel;
