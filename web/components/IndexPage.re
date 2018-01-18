module Option = {
  let unwrapUnsafely = data =>
    switch data {
    | Some(v) => v
    | None => raise(Invalid_argument("unwrapUnsafely called on None"))
    };
};

type state = {
  items: array(Data.item),
  loading: bool
};

type action =
  | Loaded(array(Data.item))
  | Loading;

let component = ReasonReact.reducerComponent("IndexPage");

let make = (~message, _children) => {
  /* demo event handler */
  let handleClick = (_event, _self) => Js.log("clicked!");
  /* load data from the api */
  let loadData = ({ReasonReact.state, reduce}) => {
    /* `Data.fetchData` accepts the function created by `reduce` */
    Data.fetchData(reduce(data => Loaded(Array.concat([state.items, data]))))
    /* this creates a promise that will eventually resolve, ignore
     * the immediate return value.
     */
    |> ignore;
    /* tell the components reducer that data is still loading until
     * the `Loaded` action is passed.
     */
    reduce(() => Loading);
  };
  /* return the updated component */
  {
    ...component,
    /* set the initial state */
    initialState: () => {items: [||], loading: true},
    /* reducer is responsible for reacting to the current action,
     * and in this case, it only updates the state once the `Loaded`
     * action has been received.
     */
    reducer: (action, _state) =>
      switch action {
      /* component is still loading, so nothing  */
      | Loading => ReasonReact.NoUpdate
      /* data has been received, so update state */
      | Loaded(data) => ReasonReact.Update({items: data, loading: false})
      },
    /* `componentDidMount` from JS API */
    didMount: self => {
      /* start fetching of API data */
      loadData(self) |> ignore;
      /* we update the state via `reducer`, so reply with `NoUpdate`
       * here.
       */
      ReasonReact.NoUpdate;
    },
    render: self =>
      <div onClick=(self.handle(handleClick))>
        (ReasonReact.stringToElement(message))
        (
          if (self.state.loading) {
            <p> (ReasonReact.stringToElement("Loading...")) </p>;
          } else {
            <ItemList items=self.state.items />;
          }
        )
      </div>
  };
};
