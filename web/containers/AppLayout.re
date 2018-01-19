let component = ReasonReact.statelessComponent("AppLayout");

let make = (~route, _children) => {
  ...component,
  render: _self =>
    <div>
      (
        switch route {
        | Routing.Home => <IndexPage message="Hello!" />
        | Routing.About => <AboutPage />
        | Routing.NotFound(path) => <NotFoundPage path />
        }
      )
    </div>
};
