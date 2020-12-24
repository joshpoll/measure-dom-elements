// https://stackoverflow.com/a/63984284

[@bs.val] external document: Js.t({..}) = "document";

let measureText = (id: string, text: string, font: string) => {
  // create a mock element
  let newText = document##createElement("text");
  newText##setAttribute("id", id);
  document##body##appendChild(newText);

  // append text data
  let theTextEle = document##getElementById(id);
  theTextEle##innerHTML #= text;

  // set text font
  theTextEle##style##font #= font;

  // measure element
  let width = theTextEle##getBoundingClientRect()##width;
  let height = theTextEle##getBoundingClientRect()##height;

  // delete element
  theTextEle##parentNode##removeChild(theTextEle);

  // TODO: return DOMRect?
  (width, height)
};