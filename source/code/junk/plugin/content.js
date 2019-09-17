function create_found_acronym() {
    return {
        node: {},
        elem: {},
    };
};

function create_node_from_text(text) {
    var outer = document.createElement("span");
    var ctext = document.createTextNode("hello wor");
    var words = tokenize_node_value(text);
    for (var j = 0; j < words.length; j++){
         if (words[j] === "engine") {
            var outer2 = document.createElement("span");
            var gg = document.createTextNode(words[j]);
            //gg.nodeValue += " ";
            outer2.appendChild(gg);
            outer.appendChild(outer2);
            
            var gg2 = document.createTextNode(" ");
            outer.appendChild(gg2);
         }
         else{
            var gg2 = document.createTextNode(words[j]);
            gg2.nodeValue += " ";
            outer.appendChild(gg2);
         }
    }
    return outer;
}


function span_out_acronyms() {
    
    var texts = get_all_text_nodes();
    for (var i = 0; i < texts.length; i++) {
        var new_node = create_node_from_text(texts[i].nodeValue);
        console.log(new_node);
        texts[i].parentNode.replaceChild(new_node,texts[i]);
    }
    
}

function get_all_text_nodes() {
    text_nodes = []
    var elements = document.body.getElementsByTagName('*');
    for (var i = 0, imax=elements.length; i < imax; i++) {
        var element = elements[i];
        for (var j = 0, jmax = element.childNodes.length; j < jmax; j++) {
            var node = element.childNodes[j];
            if (element.nodeName != "STYLE" && element.nodeName != "NOSCRIPT" && element.nodeName != "SCRIPT"){
                if (node.nodeType === Node.TEXT_NODE) {
                    text_nodes.push(node);
                }
            }
        }
    }
    return text_nodes;
}

function find_all_acronyms() {

    all_acronyms = []
    var elements = document.body.getElementsByTagName('*');
    for (var i = 0, imax=elements.length; i < imax; i++) {
        var element = elements[i];
        for (var j = 0, jmax = element.childNodes.length; j < jmax; j++) {
            var node = element.childNodes[j];
            if (element.nodeName != "STYLE" && element.nodeName != "NOSCRIPT" && element.nodeName != "SCRIPT"){
                if (node.nodeType === Node.TEXT_NODE) {
                    store_acronyms_in_node(node,element,all_acronyms);
                }
            }
        }
    }
    return all_acronyms;
}

function store_acronyms_in_node(node,element,all_acronyms){
        if (node.nodeValue === "engine") {
            var found_acronym = new create_found_acronym();
            found_acronym.node = node;
            found_acronym.elem = element;
            all_acronyms.push(found_acronym);
        }
}

function tokenize_node_value(nodeValue) {
    return nodeValue.split(" ");
}

function tooltipify(found_acronyms) {
    for (var i = 0; i < found_acronyms.length; i++) {
        
        //create outer span to make word a tooltip
        var outer = document.createElement("span");
        outer.setAttribute('class', 'tooltip');
        
        //insert acronym
        var word = document.createTextNode(found_acronyms[i].node.nodeValue);
        outer.appendChild(word);
        
        //create inner span to make tooltip text
        var inner = document.createElement("span");
        inner.setAttribute('class', 'tooltiptext');
        
        //insert definition
        var defined = document.createTextNode("hello world");
        inner.appendChild(defined);
        outer.appendChild(inner);
        
        //change the element
        found_acronyms[i].elem.replaceChild(outer, found_acronyms[i].node);
    }
}

function rewrite_dom_via_acronyms(acronym_json) {
    console.log(acronym_json);
    span_out_acronyms();
    var found_acronyms = find_all_acronyms();
    tooltipify(found_acronyms);
}

function main() {
    const url = chrome.runtime.getURL('acronym.json');
    defs = fetch(url)
      .then(function(response) {
        return response.json();
    })
    .then(acronym_json => {
        rewrite_dom_via_acronyms(acronym_json);
      })
}

main();