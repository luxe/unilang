function create_found_acronym() {
    return {
        node: {},
        elem: {},
    };
};

function find_all_acronyms() {
    all_acronyms = []
    var elements = document.getElementsByTagName('*');
    for (var i = 0; i < elements.length; i++) {
        var element = elements[i];
        for (var j = 0; j < element.childNodes.length; j++) {
            var node = element.childNodes[j];
            if (node.nodeType === Node.TEXT_NODE) {
                if (node.nodeValue === "engine") {
                    var found_acronym = new create_found_acronym();
                    found_acronym.node = node;
                    found_acronym.elem = element;
                    //elements_to_change.push(element);
                    all_acronyms.push(found_acronym);
                }
            }
        }
    }
    return all_acronyms;
}

var all_acronyms = find_all_acronyms();

for (var i = 0; i < all_acronyms.length; i++) {
    
    //create outer span to make word a tooltip
    var outer = document.createElement("span");
    outer.setAttribute('class', 'tooltip');
    
    //insert acronym
    var word = document.createTextNode(all_acronyms[i].node.nodeValue);
    outer.appendChild(word);
    
    //create inner span to make tooltip text
    var inner = document.createElement("span");
    inner.setAttribute('class', 'tooltiptext');
    
    //insert definition
    var defined = document.createTextNode("hello world");
    inner.appendChild(defined);
    outer.appendChild(inner);
    
    //change the element
    all_acronyms[i].elem.replaceChild(outer, all_acronyms[i].node);
    //elements_to_change[i].replaceChild(outer, all_acronyms[i].node);
}