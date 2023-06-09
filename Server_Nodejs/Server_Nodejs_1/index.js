//BACKEND
console.log("Server test");
const express = require('express');
const app = express();
app.use(express.static('public'));
const bodyParser = require('body-parser');
app.use(bodyParser.json());
const port = 3000; //asigno el puerto
var flag_session = 0;
//revisar una varible con user y pass
var user = "melissa.mejia";
var pass = "hiworld";

var SENSOR = {"temp1":"","hum1":"","temp2":"","hum2":""};



app.get('/', (req, res) => {
    //res.send("Petición 1 recibida")
    res.sendFile(__dirname + "/public/login.html");

});

app.get('/web', (req, res) => {
    if (flag_session == 1) {
        res.sendFile(__dirname + "/public/iot.html");
    } else {
        res.send('Sesión no iniciada');
        
    }
});
        

app.post('/login', (request, res) => {
    var data = JSON.parse(JSON.stringify(request.body));
    console.log(request);
    res.status(200);
    console.log('petición recibida');
    console.log(data);
    //verifico si el usuario coincide con lo que está pisado
    if ((data.usr === user) && (data.pass === pass)){
        res.send('OK');
        flag_session = 1;
    } else {
        res.send('ERROR');
    }


});

app.post('/data',(req,res) => {
    var data = JSON.parse(JSON.stringify(req.body));
    console.log('datos Sensor recibidos');
    console.log('Sensor:' + data.id);
    console.log('Temp:' + data.temp);
    console.log('Hum:' + data.hum);
    if(data.id == 1){
        SENSOR.temp1 = data.temp;
        SENSOR.hum1 = data.hum;
    }else if(data.id == 2){
        SENSOR.temp2 = data.temp;
        SENSOR.hum2 = data.hum;
    }
    res.status(200);
    res.send('OK');
});

app.get('/sens1',(req, res) => {
    var data = {"temp":SENSOR.temp1,"hum":SENSOR.hum1};
    res.status(200);
    res.send(data);    
});

app.get('/sens2',(req, res) => {
    var data = {"temp":SENSOR.temp2,"hum":SENSOR.hum2};
    res.status(200);
    res.send(data);    
});





app.listen(port, () => {
    console.log("Server in http://localhost:" + port)


 }); //aquí pondré la funcionalidad
