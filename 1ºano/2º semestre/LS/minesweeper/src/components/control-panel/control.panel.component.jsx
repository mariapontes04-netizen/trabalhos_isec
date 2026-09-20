import React from "react";
import "./control-panel.css";
import Timer from "../timer/timer.component"

function ControlPanel(props) {
  const {gameStarted,selectedLevel,onGameStart,onLevelChange,win}=props;
  const gameStartedClass=gameStarted?" gameStarted":"";
  
  return (
    <main className="main-content">
    {/* <!-- Painel de controlo --> */}
    <section id="panel-control">    
    <h3 className="sr-only">Escolha do Nível</h3>
    <form className="form">
    <fieldset className="form-group">
    <label htmlFor="btLevel">Nível:</label>
    <select id="btLevel" onChange={onLevelChange} disabled={gameStarted}>
    <option value="0">Seleccione...</option>
    <option value="1">Básico (9x9-10 minas)</option>
    <option value="2">Intermédio (16x16-40 minas)</option>
    <option value="3">Avançado (30x16-99 minas)</option>
    </select>
    </fieldset>
    <button type="button" id="btPlay" onClick={onGameStart} disabled={selectedLevel==="0"} >{gameStarted?"Terminar Jogo":"Iniciar Jogo"}</button>
    </form>
    <div className="form-metadata">
    <p id="message" role="alert" className="hide" >
     Clique em Iniciar o Jogo!
     </p>
    <dl className={`list-item left${gameStartedClass}`}>
    <dt>Tempo de Jogo:</dt>
    <dd id="gameTime">{gameStarted &&<Timer win={win}/>}s</dd>
    </dl>
    </div>
    </section>
    </main>
        
  );
}

export default ControlPanel;