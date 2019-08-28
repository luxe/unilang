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
                    all_acronyms.push(found_acronym);
                }
            }
        }
    }
    return all_acronyms;
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