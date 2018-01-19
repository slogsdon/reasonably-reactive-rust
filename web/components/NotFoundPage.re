let component = ReasonReact.statelessComponent("NotFoundPage");

let string_of_path = path => "/" ++ String.concat("/", path);

let make = (~path, _children) => {
  ...component,
  render: _self =>
    <div>
      <h1> (ReasonReact.stringToElement("Not Found")) </h1>
      <p>
        (ReasonReact.stringToElement("The page at "))
        <code> (ReasonReact.stringToElement(string_of_path(path))) </code>
        (ReasonReact.stringToElement(" cannot be found."))
      </p>
    </div>
};
