//Backend
console.log("Server test IoT ");
const express = require('express');
const app = express();
app.use(express.static('public'));//usamos carpeta public para almacenar frontend
const port=3000;
var flag_sesion=0;
var user = "Alejo";
var pass = "1234";
//app.get('',(req, res) =>{});

app.get('/',(req, res) =>{
    res.sendFile(__dirname + "/public/login.html");

});

app.get('/web',(req, res) =>{
    if(flag_sesion==1){
        res.sendFile(__dirname + "/public/web1.html");
    }else{
        res.send('Sesión no iniciada')
    }
});

app.post('/login',(req,res) =>{
    var data = JSON.parse(req.body);
    console.log(data);
    res.status(200);
    if((data.usr === user) && (data.pass === pass)){
        res.send('OK');
        flag_sesion=1;
    }else{
        res.send('ERROR');
    }
});


app.listen(port, () => {
    console.log('Servidor iniciado en http://localhost:'+port);

});


