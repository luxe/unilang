function create_found_acronym() {
    return {
        node: {},
        elem: {},
    };
};

function find_all_acronyms() {
    all_acronyms = []
    var elements = document.body.getElementsByTagName('*');
    for (var i = 0; i < elements.length; i++) {
        var element = elements[i];
        for (var j = 0; j < element.childNodes.length; j++) {
            var node = element.childNodes[j];
            console.log(element.nodeName);
            
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
    
    
    var span = element.ownerDocument.createElement('span');
    var continued_text = document.createTextNode("hello");
    node.parentNode.replaceChild(continued_text, node);
    
    // var replaced_tag = document.createElement("span");
    // //element.replaceChild(replaced_tag,node);
    // // var continued_text = document.createTextNode("");
    
    // tokenized = tokenize_node_value(node.nodeValue);
    // for (var k = 0; k < tokenized.length; k++){
    //     if (tokenized[k] === "engine") {
    //         var found_acronym = new create_found_acronym();
    //         found_acronym.node = node;
    //         found_acronym.elem = element;
    //         all_acronyms.push(found_acronym);
    //     }
    // }
            
    //         //add the current text
    //         replaced_tag.appendChild(continued_text);
    //         continued_text.nodeValue = "";
            
    //         var outer = document.createElement("span");
            
    //         //re-insert acronym
    //         var word = document.createTextNode("engine");
    //         outer.appendChild(word);
            
    //         replaced_tag.appendChild(outer);
    //     }
    //     else{
    //         continued_text.nodeValue += tokenized[k] + " ";
    //     }
    // }
    
    // //add the current text
    // replaced_tag.appendChild(continued_text);
    // continued_text.nodeValue = "";
    
    // element.replaceChild(replaced_tag,node);
            
    //console.log(continued_text.nodeValue);
    
    //node.parentNode.replaceChild(replaced_tag,node);
    
    
    //replaced_tag.nodeValue = node.nodeValue;
    //replaced_tag.nodeValue += " test ";
    //node.parentNode.replaceChild(replaced_tag,node);
    
    
    
    // tokenized = tokenize_node_value(node.nodeValue)
    // for (var k = 0; k < tokenized.length; k++){
    //     if (tokenized[k] === "engine") {
            
    //         var word_tag = document.createTextNode(tokenized[k]);
    //         replaced_tag.appendChild(word_tag);
            
            
    //         var found_acronym = new create_found_acronym();
    //         //found_acronym.node = node;
    //         found_acronym.node = word_tag;
    //         found_acronym.elem = element;
    //         all_acronyms.push(found_acronym);
    //     }
    //     else{
    //         replaced_tag.nodeValue += tokenized[k];
    //     }
    // }
    
    //console.log(replaced_tag.nodeValue);
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