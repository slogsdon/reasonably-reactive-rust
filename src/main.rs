#![feature(plugin)]
#![plugin(rocket_codegen)]

extern crate rocket;
extern crate rocket_contrib;
extern crate serde;
#[macro_use]
extern crate serde_derive;
extern crate serde_json;

use std::path::{Path, PathBuf};
use rocket::response::NamedFile;
use rocket_contrib::Json;

#[derive(Serialize)]
struct Item {
    name: &'static str,
}

#[get("/")]
fn index() -> Option<NamedFile> {
    NamedFile::open("static/index.html").ok()
}

#[get("/<file..>")]
fn files(file: PathBuf) -> Option<NamedFile> {
    NamedFile::open(Path::new("static/").join(file)).ok()
}

#[get("/api/items")]
fn items() -> Json<Vec<Item>> {
    let items = vec![Item { name: "foo" }, Item { name: "bar" }];
    Json(items)
}

fn main() {
    rocket::ignite()
        .mount("/", routes![index, files, items])
        .launch();
}
