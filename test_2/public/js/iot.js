/*var USER = {usr:"", pass:""};

//function Remplazar1(var1,var2)
function enviar(){
    //document.getElementById('titulo1').textContent = document.getElementById('mail').value;
    USER.usr = document.getElementById('user').value;
    USER.pass = document.getElementById('pass').value;

    //Inicio petición POST
    $.post({
        url: "/login", //A que URL va a ir esta petición
        data: JSON.stringify(USER), //Convierto el vector json a texto para poderlo enviar
        contentType: "application/json", //Le digo que tipo de dato le va a llegar
        success: function(datosRes, status){
            if(datosRes === "OK"){
                window.location.replace("/web");
            }else if(datosRes === "Error"){
                alert("Acceso denegado");
            }
        }
    });
}*/

function datos(){
    $.get({
        url: "/sens",
        success: function(datosRes, status){            
            document.getElementById('temp1').innerHTML = datosRes.temp1;
            document.getElementById('Hum1').innerHTML = datosRes.Hum1;   
            document.getElementById('Calidad').innerHTML = datosRes.Calidad;            
        }
    });
}

