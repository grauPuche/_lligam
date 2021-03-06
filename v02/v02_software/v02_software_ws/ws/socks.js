var WebSocketServer = require('websocket').server;
var http = require('http');

var server = http.createServer(function(request, response) {
  // process HTTP request. Since we're writing just WebSockets
  // server we don't have to implement anything.
});
server.listen(7013, function() { 
  console.log((new Date()) + " Server is listening on port 7013");
});

// create the server
wsServer = new WebSocketServer({
  httpServer: server
});

// WebSocket server
wsServer.on('request', function(request) {
  var connection = request.accept(null, request.origin);

  console.log("client connected")

  // This is the most important callback for us, we'll handle
  // all messages from users here.
  connection.on('message', function(message) {
    if (message.type === 'utf8') {
      // process WebSocket message
      console.log('new message: '+ message)
    }
  });

  connection.on('close', function(connection) {
    // close user connection
    console.log("client disconnected")
  });
});





 // "use strict";

// // Optional. You will see this name in eg. 'ps' or 'top' command
// process.title = 'joyData';

// // Port where we'll run the websocket server
// var webSocketsServerPort = 3001;

// // websocket and http servers
// var webSocketServer = require('websocket').server;
// var http = require('http');

// /* Global variables */

// // list of currently connected clients (users)
// var clients = [ ];

// /* Helper function for escaping input strings */

// function htmlEntities(str) {
//   return String(str)
//       .replace(/&/g, '&amp;').replace(/</g, '&lt;')
//       .replace(/>/g, '&gt;').replace(/"/g, '&quot;');
// }

// /* HTTP server */

// var server = http.createServer(function(request, response) {
//   // Not important for us. We're writing WebSocket server, not HTTP server
// });

// server.listen(webSocketsServerPort, function() {
//   console.log((new Date()) + " Server is listening on port "
//       + webSocketsServerPort);
// });

// /* WebSocket server */

// var wsServer = new webSocketServer({
//   // WebSocket server is tied to a HTTP server. WebSocket request is just an enhanced HTTP request. For more info http://tools.ietf.org/html/rfc6455#page-6
//   httpServer: server
// });

// // This callback function is called every time someone tries to connect to the WebSocket server
// wsServer.on('request', function(request) {
//   console.log((new Date()) + ' Connection from origin '
//       + request.origin + '.');

//   // accept connection - you should check 'request.origin' to make sure that client is connecting from your website (http://en.wikipedia.org/wiki/Same_origin_policy)
//   var connection = request.accept(null, request.origin);

//   // we need to know client index to remove them on 'close' event
//   var index = clients.push(connection) - 1;
//   console.log((new Date()) + ' Connection accepted.');
  
  
//   // // user sent some message
//   // connection.on('message', function(message) {
//   //   if (message.type === 'utf8') { // accept only text
//   //   // first message sent by user is their name
//   //    if (userName === false) {
//   //       // remember user name
//   //       userName = htmlEntities(message.utf8Data);
//   //       // get random color and send it back to the user
//   //       userColor = colors.shift();
//   //       connection.sendUTF(
//   //           JSON.stringify({ type:'color', data: userColor }));
//   //       console.log((new Date()) + ' User is known as: ' + userName
//   //                   + ' with ' + userColor + ' color.');
//   //     } else { // log and broadcast the message
//   //       console.log((new Date()) + ' Received Message from '
//   //                   + userName + ': ' + message.utf8Data);
        
//   //       // we want to keep history of all sent messages
//   //       var obj = {
//   //         time: (new Date()).getTime(),
//   //         text: htmlEntities(message.utf8Data),
//   //         author: userName,
//   //         color: userColor
//   //       };
//   //       history.push(obj);
//   //       history = history.slice(-100);
//   //       // broadcast message to all connected clients
//   //       var json = JSON.stringify({ type:'message', data: obj });
//   //       for (var i=0; i < clients.length; i++) {
//   //         clients[i].sendUTF(json);
//   //       }
//   //     }
//   //   }
//   // });

//   // user disconnected
//   connection.on('close', function(connection) {
//       console.log((new Date()) + " Peer "
//           + connection.remoteAddress + " disconnected.");
//       // remove user from the list of connected clients
//       clients.splice(index, 1);
//       // push back user's color to be reused by another user
//   });
// });
