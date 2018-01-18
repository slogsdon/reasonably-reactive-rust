type item = {name: string};

module Decode = {
  let item = json : item => Json.Decode.{name: json |> field("name", string)};
  let itemList = json : array(item) => Json.Decode.(json |> array(item));
};

let fetchData = callback =>
  Js.Promise.(
    Fetch.fetch("/api/items")
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Decode.itemList
         |> (
           items => {
             callback(items);
             resolve();
           }
         )
       )
    |> ignore
  );
