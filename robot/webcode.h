#ifndef WEBCODE_H
#define WEBCODE_H
#include <Arduino.h>
String webcode =
R"=====( "<html>
<head>


<style>
body{
    align-items:center;
text-align: center;
}
#buttonpanel {
    text-align:center;
align-items: center;
}
button {
    background-color: rgb(125, 235, 52);
width: 300px;
height: 300px;

align-items: center;
font-size: 50;
}

#st {
float:center;
position:absolute;
left: 50%;
top: 50%;
}
#lt {
    float:center;
position:absolute;
left: 15%;
top: 50%;
}
#rt{
    float:center;
position:absolute;
left: 85%;
top: 50%;
}
#fd{
    float:center;
position:absolute;
left: 50%;
top: 30%;
}
#bw{
    float:center;
position:absolute;
left: 50%;
top: 70%;
}


</style>
<title>Robot Control</title>
</head>
<body>;
   
   <div id="buttonpanel">
    <h1>Robot Control by Koder</h1>
    <p><a href='/forward'><button id = "fd">Forward</button></a></p>
    <p><a href='/backward'><button id = "bw">Backward</button></a></p>
    <p><a href='/stop'><button id = "st">Stop</button></a></p>
    <p><a href='/left'><button id = "lt">Left</button></a></p>
    <p><a href='/right'><button id = "rt">Right</button></a></p>
   

   </div>
    



   </body></html>
   )=====";
#endif