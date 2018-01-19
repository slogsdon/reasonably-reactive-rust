let component = ReasonReact.statelessComponent("Link");
let make = (~to_, children) => {
  ...component,
  render: (_self) => {
    <a href=(to_) onClick=((event) => {
      ReactEventRe.Synthetic.preventDefault(event);
      ReasonReact.Router.push(to_);
    })>(ReasonReact.arrayToElement(children))</a>
  }
};
