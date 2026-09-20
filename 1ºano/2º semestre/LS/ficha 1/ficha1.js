//2.a
/*'use strict';
const num1=5;
const num2=10;

if(num1>num2){
    console.log('O maior entre '+num1+', '+num2+' = '+num1);
}
else if(num2>num1){
    console.log('O maior entre '+num1+', '+num2+' = '+num2);
}
else if(num1==num2){
    console.log('Os números são iguais!');
}
 num1==num2?console.log('números iguais'):console.log();*/



//2.b
/*'use strict';
const num1=10;
const num2=10;
const num3=15;

if(num1>num2 && num1>num3){
    console.log('O maior entre '+num1+', '+num2+', '+num3+' = '+num1);
}
else if(num2>num1 && num2>num3){
    console.log('O maior entre '+num1+', '+num2+', '+num3+' = '+num2);
}
else if(num3>num1 && num3>num2){
    console.log('O maior entre '+num1+', '+num2+', '+num3+' = '+num3);
}
else if(num1==num2 && num2==num3 && num1==num3){
    console.log('Os números são iguais!');
}*/
//const maior=Math.max(num1,num2,num3);



//2.c
/*'use strict';
const min=5;
const max=10;
const soma=0;
for(let i=min;i<=max;i++){
    soma+=i;
}
console.log('Soma='+soma);*/



//3.b
/*const numeros = [5,10,-12,2,15,-5,-2,-3];
let maior=numeros[0];
for(let i=1;i<=numeros.length;i++){
    if(numeros[i]>maior){
        maior=numeros[i];
    }
}
console.log("Maior é "+ maior);*/
// console.log(Math.max(...numeros));



//3.c
/*const numeros = [5,10,-12,2,15,-5,-2,-3];
let soma=0;
for(let i=0;i<=numeros.length;i++){
    if(numeros[i]>0){
        soma+=numeros[i];
    }
}
console.log('Soma='+soma);*/

/*const numeros = [5,10,-12,2,15,-5,-2,-3];
let soma=0;
numeros.forEach((num)=>(num>0?(soma+=num):0));*/



//5.a)
//function compara(n1, n2){
    /*if(n1===n2){
        return true;
    }
    else{
        return false;
    }*/

    /*let resultado;
    (n1===n2)?resultado=true:resultado=false;
    return resultado;*/
//}


//5.b)
/*parOuImpar(5); //Deverá escrever ‘O número é impar!’
parOuImpar(4); //Deverá escrever ‘O número é par!’

function parOuImpar(n){
    console.log(
        isNaN(n)?"Não é um número":
        (n%2===0)?n+" é par ":n+" é impar "
    );
}
parOuImpar("hi");*/



//5.c)
/*console.log(obtemQuadrado(2)) //Será apresentado 4 na consola
console.log(obtemQuadrado(9)) //81
console.log(obtemQuadrado(10)) //100

function obtemQuadrado(q){
    return q*q;
}*/




//5.d)
/*console.log(areaRetangulo(5,10)) // 50
console.log(areaRetangulo(10,20)) // 200
console.log(areaRetangulo(5)) // 25

function areaRetangulo(a,b=a){
    return a*b;
}*/



//5.e)
/*console.log(contaVogais("Ola")) //2
console.log(contaVogais("Linguagens Script")) //5

function contaVogais(str){
    let conta=0;
    str=str.toLowerCase();
    for(let i=0;i<str.length;i++){
        if(str.charAt(i)=="a" || str.charAt(i)=="e" || str.charAt(i)=="i" || str.charAt(i)=="o" || str.charAt(i)=="u"){
            conta++;
        }
    }
    return conta;
}*/



//5.f)
const palavras=['angular','bootstrap','javascript','vue','svelte','react'];

function imprimeArray(arr){
    for(let elemento of arr){
        console.log(elemento);
    }
}
function insertBegin(arr, elemento){
    for(let i=arr.length;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=elemento;
}
console.log(insertBegin(palavras,"ember"));
