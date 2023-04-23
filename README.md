# orpfinder

[![GitHub version](https://img.shields.io/github/v/release/xvitaly/orpfinder?sort=semver&color=brightgreen&logo=git&logoColor=white)](https://github.com/xvitaly/orpfinder/releases)
[![Fedora CI](https://github.com/xvitaly/orpfinder/actions/workflows/fedora.yml/badge.svg)](https://github.com/xvitaly/orpfinder/actions/workflows/fedora.yml)
[![Ubuntu CI](https://github.com/xvitaly/orpfinder/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/xvitaly/orpfinder/actions/workflows/ubuntu.yml)
[![IWYU CI](https://github.com/xvitaly/orpfinder/actions/workflows/iwyu.yml/badge.svg)](https://github.com/xvitaly/orpfinder/actions/workflows/iwyu.yml)
[![CodeQL](https://github.com/xvitaly/orpfinder/actions/workflows/codeql.yml/badge.svg)](https://github.com/xvitaly/orpfinder/actions/workflows/codeql.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/269e90827fa5459db0ed7305f6f74ec0)](https://www.codacy.com/gh/xvitaly/orpfinder/dashboard)
[![CodeFactor](https://www.codefactor.io/repository/github/xvitaly/orpfinder/badge)](https://www.codefactor.io/repository/github/xvitaly/orpfinder)
[![GitHub issues](https://img.shields.io/github/issues/xvitaly/orpfinder.svg?label=issues&maxAge=180)](https://github.com/xvitaly/orpfinder/issues)
---

## About

Orpfinder is a simple command line tool for finding packages that no one depends on in repositories.

Such packages can be safely removed.

## License

This project is licensed under the terms of the [MIT license](LICENSE).

## Installation

```
sudo dnf copr enable xvitaly/ecrepo
sudo dnf install orpfinder
```
