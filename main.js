function setColor(){
    let text = $("#textarea").val();

    let coloredText = text.replace(/[\+\-\*\/\{\}\>\<\=\!]+/g, '<symbol>$&</symbol>')
                .replace(/[\n]/g, '<br/>')
                .replace(/\t/g, '&emsp;')
                .replace(/si|SI|Si/g, '<si>$&</si>')
                .replace(/Sinon|sinon|SINON/g, '<si>$&</si>')
                .replace(/Pour|pour|POUR[ \n\t\r]+/g, '<loop>$&</loop>')
                .replace(/Tant que|tant que|TANT QUE/g, '<loop>$&</loop>')
                .replace(/fonction|Fonction|FONCTION/g, '<func>$&</func>')
                .replace(/def|DEF|def/g, '<func>$&</func>')
                .replace(/tracer|Tracer|TRACER/g, '<plot>$&</plot>');
                
        $("#coloredText").empty();
        $("#coloredText").append(coloredText); 
}

$("#textarea").keydown(() => {
    setTimeout(setColor, 100);
});



$("*").click(() => {
    $("#textarea").focus();
});


$("#textarea").focus();

if(a>2){
    a++;
}