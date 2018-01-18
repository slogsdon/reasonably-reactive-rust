let component = ReasonReact.statelessComponent("ItemList");

let make = (~items, _children) => {
  ...component,
  render: _self =>
    <ul>
      (
        items
        |> Array.mapi((index: int, item: Data.item) =>
             <li key=(string_of_int(index))>
               (ReasonReact.stringToElement(item.name))
             </li>
           )
        |> ReasonReact.arrayToElement
      )
    </ul>
};
