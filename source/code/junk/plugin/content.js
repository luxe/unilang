var elements = document.getElementsByTagName('*');
var nodes_to_change = []
var elements_to_change = []

for (var i = 0; i < elements.length; i++) {
    var element = elements[i];
    for (var j = 0; j < element.childNodes.length; j++) {
        var node = element.childNodes[j];
        if (node.nodeType === 3) {
            if (node.nodeValue === "engine") {
                nodes_to_change.push(node)
                elements_to_change.push(element)
                //var toolTipDiv = document.createElement("strong");
                //var word_inside = document.createTextNode(node.nodeValue);
                //toolTipDiv.appendChild(word_inside);
                //element.replaceChild(toolTipDiv, node);
            }
        }
    }
}

for (var i = 0; i < nodes_to_change.length; i++) {
	var toolTipDiv = document.createElement("u");
        toolTipDiv.setAttribute('class', 'tooltip');
        var word_inside = document.createTextNode(nodes_to_change[i].nodeValue);
        toolTipDiv.appendChild(word_inside);
        elements_to_change[i].replaceChild(toolTipDiv, nodes_to_change[i]);
}


//console.log(nodes_to_change.length)
//alert(nodes_to_change.length)
