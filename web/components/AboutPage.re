let component = ReasonReact.statelessComponent("AboutPage");
let make = (_children) => {
  ...component,
  render: (_self) => {
    <div>
      <h1>(ReasonReact.stringToElement("About"))</h1>
      <Link to_="/">(ReasonReact.stringToElement("Index"))</Link>
    </div>
  }
};
