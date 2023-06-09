var A = "texto1";
var B = 10.5;
var USR = {mail:"", pass:"", int:0};

//Function Reemplazar1(var1,var2)

function Reemplazar1(){
    //document.getElementById('titulo1').innerHTML = document.getElementById('mail').value;
    USR.mail = document.getElementById('mail').value;
    USR.pass = document.getElementById('pass').value;
    document.getElementById('titulo1').innerHTML = USR.mail;
}

function potencia(num1,num2){
    var res = Math.pow(num1,num2);
}

function suma(){
    var n1 = parseFloat(document.getElementById('n1').value);
    var n2 = parseFloat(document.getElementById('n2').value);
    var res = n1 + n2;
    document.getElementById('res').value = res;
}


function Random(){
    var min = parseInt(document.getElementById('min').value);
    var max = parseInt(document.getElementById('max').value);
    var res = Math.floor((Math.random()*max)+min);
    document.getElementById('res1').value=res;
}