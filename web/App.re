let render = route =>
  ReactDOMRe.renderToElementWithId(<AppLayout route />, "root");

let _ =
  ReasonReact.Router.watchUrl(url =>
    switch url.path {
    | ["about"] => render(Routing.About)
    | [] => render(Routing.Home)
    | path => render(Routing.NotFound(path))
    }
  );

ReasonReact.Router.push([%bs.raw {| window.location.pathname |}]);
