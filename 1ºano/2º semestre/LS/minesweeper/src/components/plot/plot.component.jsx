import React, { useState, useEffect } from "react";
import "./plot.css";

function Plot(props) {
  const { row, col, isMine, handlePlotClick, isClicked, adjacentBombs, win } = props;
  const [click, setClicked] = useState(isClicked);
  const [flagStatus, setFlagStatus] = useState(0);
  useEffect(() => {
    setClicked(isClicked);
    
  }, [isClicked]);

  let classClicked = click ? "inactive" : "";
  let verify = 0;

  const handleLeftClick = () => {
    if (win === 1 && !click && !flagStatus) {
      handlePlotClick(row, col);
    }
  };

  const handleRightClick = (e) => {
    if(win===1)
      {
        e.preventDefault(); // Prevent the default context menu from appearing
    if (!click) {
      setFlagStatus((prevStatus) => (prevStatus + 1) % 3);
    }
      }
    
  };

  return (
    <div
      onClick={handleLeftClick}
      onContextMenu={handleRightClick}
      className={`plot ${classClicked}`}
      data-logo={`${row}-${col}`}
    >
      {isClicked ? "" : flagStatus === 1 ? "🚩" : flagStatus === 2 ? "?" : ""}
      {isClicked ? (isMine ? "💣" : adjacentBombs) : ""}
    </div>
  );
}

export default Plot;