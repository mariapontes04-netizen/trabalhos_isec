function exemplo(){
    alert("Exercício Javascript!");
}
document.getElementById("btn-alert2").addEventListener("click",exemplo);

// function exemplo(){
//     alert("Exercicio Javascript !!!");
// }
// document.getElementById("btn-alert2").addEventListener("click",function(){exemplo});

// document.getElementById("btn-alert2").addEventListener("click",function(){alert("Exercicio Javascript !!")});



document.getElementById("btn-titulo").addEventListener("click",function(){
    document.querySelector(".title").textContent="Tecnologias Web - Javascript";
});




document.getElementById("btn-titulo").addEventListener("mouseover",function(){
    document.querySelector(".title").innerHTML="<h4>Introdução ao Javascript</h4>";
});

document.querySelector("#btn-titulo").addEventListener("mouseover",function(){
    document.querySelector(".title").innerHTML="Introdução ao Javascript";
});



document.querySelector(".btn-border").addEventListener("click",function(){
let panel=document.querySelector(".panel-animals");

    if(panel.classList.contains("border-active")){
        panel.classList.remove("border-active");
        panel.style.backgroundColor="white";
    }
    else{
        panel.classList.add("border-active");
        panel.style.backgroundColor="#FF000022";
    }
});

