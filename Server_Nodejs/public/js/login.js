
var A = "texto1";
var B = 10.5;
var USR = {usr:"",pass:""};
var d = new Date();//creamos un objeto tipo fecha

//function Reemplazar1(var1,var2)
function enviar(){
    //document.getElementById('titulo1').innerHTML= document.getElementById('mail').value;
    USR.usr = document.getElementById('user').value;
    USR.pass = document.getElementById('pass').value;  

    //Inicio petición post
    
    $.post({
        url: "/login",// a que url va a ir esta petición
        data: JSON.stringify(USR),// convierto el vector texto para enviarlo
        contentType: "application/json",// le digo el tipo de dato que le va a llegar
        success: function(datosRes, status){
            if(datosRes === "OK"){
                window.location.replace("/web");
            }else if (datosRes === "ERROR"){
                alert("Acceso Denegado");
            }

        }



    });


}

