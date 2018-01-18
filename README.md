# Reasonably Reactive Rust

Featuring:

- [Rust](https://www.rust-lang.org/) + [Rocket](https://rocket.rs)
- [React](https://reactjs.org/)
- [Reason](https://reasonml.github.io/) + [ReasonReact](https://reasonml.github.io/reason-react/) for typesafe use of React
- [Parcel](https://parceljs.org/) for bundling the frontend assets

## Requirements

- [Node.js](https://nodejs.org/)
- [Yarn](https://yarnpkg.com/docs/install/) or [npm](https://docs.npmjs.com/getting-started/installing-node)
- [Reason](https://reasonml.github.io/docs/global-installation.html)
- [Rust nightly](https://www.rust-lang.org/install.html)
- [`cargo-watch`](https://github.com/passcod/cargo-watch) if you want to use the `yarn develop` script

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

## Need a Reset?

```
yarn clean
```

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for more details.
