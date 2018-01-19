# Reasonably Reactive Rust

> Demo/starter project using Reason + React and Rust + Rocket

Featuring:

* [Rust](https://www.rust-lang.org/) + [Rocket](https://rocket.rs)
* [React](https://reactjs.org/)
* [Reason](https://reasonml.github.io/) + [ReasonReact](https://reasonml.github.io/reason-react/)
* [Parcel](https://parceljs.org/)

### Reasoning

This project was primarily created to combine some new technologies in order to see what a more complete project could look like and how the individual parts would work together. Specifics:

* Rust: fast and safe code without garbage collection
* Rocket: developer-focused conveniences over type safe code
* Reason and ReasonReact: type safe interactions React and JavaScript
* Parcel: frontend asset bundling with minimal configuration

## Requirements

* [Node.js](https://nodejs.org/)
* [Yarn](https://yarnpkg.com/docs/install/) or [npm](https://docs.npmjs.com/getting-started/installing-node)
* [Reason](https://reasonml.github.io/docs/global-installation.html)
* [Rust nightly](https://www.rust-lang.org/install.html)
* [`cargo-watch`](https://github.com/passcod/cargo-watch) if you want to use the `yarn develop` script

## Getting Started

```
rustup override set nightly
yarn install
yarn develop
```

`yarn develop` will run Parcel in watch mode and leverage `cargo-watch` to rebuild frontend and backend applications on file change.

## Building for Production

```
yarn build
cargo build --release
```

The result can be started with:

```
ROCKET_ENV=production cargo run --release
```

or your preferred manner.

## Need a Reset?

```
yarn clean
```

## F.A.Q.

<dl>
  <dt>Parcel is too new/unproven and/or is missing <code>$FEATURE</code>. Can it be changed out for <code>$PREFERRED_BUNDLER</code>?</dt>
  <dd>Parcel was specifically chosen for this purpose because it requires minimal configuration to get started. To swap it out, remove Parcel as a dependency (e.g. <code>yarn remove parcel-bundler</code>), add another bundler (e.g. <code>yarn add --dev $PREFERRED_BUNDLER</code>), and update the <code>scripts</code> in <code>package.json</code> to use that bundler.</dd>
  <dt>Rust nightly changes too frequently. What now?</dt>
  <dd>Rust stable will need to be setup as the default for the project (e.g. <code>rustup override set stable</code>). This would require a change from Rocket to something else. See below.</dd>
  <dt>Rocket has too much magic. What are alternative options?</dt>
  <dd><a href="http://www.arewewebyet.org/">Are we <em>web</em> yet?</a> has a list of potential alternatives. Once one has been selected, replace Rocket specific dependencies in <code>Cargo.toml</code> and code in <code>src</code> with <code>$PREFERRED_WEB_FRAMEWORK</code> related goodies.</dd>
</dl>

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for more details.
