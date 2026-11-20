# Contributing to Neutron

This guide explains where to start and how to contribute to the Neutron codebase.

## Getting started

Before submitting a pull request, please read:

* **If your work is AI-assisted:** [AI-assisted work guidelines](CONTRIBUTING.md#ai-assisted-work)
* **If you're new to the codebase:** [Dev Quickstart](/docs/dev-quickstart.md)

Not sure where to start? Browse the [open issues labeled `complexity:low`](https://github.com/zerfithel/Neutron/issues?q=is:open+label:complexity:low).

## Reporting problems

Before opening an issue:

* Search [existing issues](https://github.com/zerfithel/Neutron/issues),
including closed ones.
* Confirm that the issue persists in the latest version of Neutron.
* For crashes, include a backtrace from libsanitizer.
* For build-related issues, include the output of `cmake --system-information`.
* Describe the expected and actual behavior,
and provide steps to reproduce the issue.

## Development guidelines

* Follow the patterns and conventions already used in the project. For example,
in function arguments, specify an array's size before the array itself.
* Prefer the simplest solution that meets the requirements. Avoid over-engineering.
* Avoid cosmetic changes unrelated to the purpose of your pull request.
* Keep your code portable. If portability requires an external dependency,
use `#ifdef` where possible or open a discussion proposing the dependency.
* Write modern, idiomatic and simple C. For reference, prefer `static inline` functions
over function-like macros, use `constexpr`
instead of `#define` macros whenever possible
and use `nullptr` instead of `NULL`.

## Pull requests

### Guidelines

* Make changes on a separate branch, not directly on the `main` branch.
* Include tests for new features and bug fixes.
* Run the relevant tests and checks before submitting your pull request.
* Keep unrelated changes in separate pull requests.
* If your work isn't ready for review, mark the pull request as a draft.
When you are ready, [change it's state to ready](https://docs.github.com/en/pull-requests/how-tos/create-pull-requests/changing-the-stage-of-a-pull-request).
* Request a review only when the pull request is ready.

### Pull request titles and commit messages

This project uses a modified [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)
format:

```text
type(scope): description
```

### Merging to main

For maintainers: when a PR is ready to merge:

* Use *Squash and Merge* when PR has only one meaningful commit.
* Use *Merge* when PR has multiple meaningful commits.
