let render = route =>
  ReactDOMRe.renderToElementWithId(<AppLayout route />, "root");

let _ =
  ReasonReact.Router.watchUrl(url =>
    switch url.path {
    | ["about"] => render(Routing.About)
    | _ => render(Routing.Home)
    }
  );

ReasonReact.Router.push([%bs.raw {| window.location.pathname |}]);
