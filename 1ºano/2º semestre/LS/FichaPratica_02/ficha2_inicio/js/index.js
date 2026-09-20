"use strict";

const panelControl=document.getElementById("panel-control"); // permite aceder ao elemento #panel-control
const panelGame=document.getElementById("game"); // permite aceder ao elemento #game
const btLevel=document.getElementById("btLevel"); // permite aceder ao elemento #btLevel
const btPlay=document.getElementById("btPlay"); // permite aceder ao elemento #btPlay
const message=document.getElementById("message"); // permite aceder ao elemento #message
const elementos=document.querySelectorAll(".list-item");
let cards=document.querySelectorAll(".card");
let cardsLogos=["angular",
                "bootstrap",
                "html",
                "javascript",
                "vue",
                "svelte",
                "react",
                "css",
                "backbone",
                "ember",];

function reset(){
    message.textContent="";
    message.classList.remove('hide');

    if(btLevel.value==="0"){
        btPlay.disabled=true;
        panelGame.style.display="none";        
    }
    else{
        btPlay.disabled=false;
        panelGame.style.display="grid";
    }
    elementos.forEach(function(elementos){
        elementos.classList.remove("gameStarted");
    }) 
}
reset();

btLevel.addEventListener("change",reset);

btPlay.addEventListener("click",function(){
    if(btPlay.textContent==="Terminar Jogo"){
        stopGame();
    }
    else{
        startGame();
    }
})

function startGame(){
    //showCards();
    console.table(cardsLogos);
    shuffleArray(cardsLogos);
    console.table(cardsLogos);
    
    let newCardLogos=cardsLogos.slice(0,3);
    newCardLogos=[...newCardLogos, ...newCardLogos];
    shuffleArray(newCardLogos);
    console.table(newCardLogos);
    
    btLevel.disabled=true;
    btPlay.textContent="Terminar Jogo";
    message.classList.add("hide");

    elementos.forEach(function(elementos){
        elementos.classList.add("gameStarted")
    })

    let indice=0;
    for(let card of cards){
        let cardFront=card.querySelector(".card-front");
        cardFront.src=`images/${newCardLogos[indice]}.png`;
        card.dataset.logo=newCardLogos[indice];
        indice++;
        card.addEventListener('click',flipCard);
    }
}
function flipCard(){
    this.classList.add("flipped");
}

function stopGame(){
    hideCards();
    btPlay.textContent="Iniciar Jogo";
    btLevel.disabled=false;
    reset();
}

panelGame.addEventListener("click", ()=>
    message.textContent = message.textContent === ''? "Clique em Iniciar o Jogo!" :''
);

function showCards(){
    for(let card of cards){
        card.classList.add("flipped");
    }
}

function hideCards(){
    for(let card of cards){
        card.classList.remove("flipped");
    }
}

// Algoritmo Fisher-Yates - Algoritmo que baralha um array
const shuffleArray = array => {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        const temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

