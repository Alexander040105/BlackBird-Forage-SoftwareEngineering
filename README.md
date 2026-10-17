# BlackBird-Forage-SoftwareEngineering

**Blackbird Australia — Software Engineering Virtual Experience on Forage** · Completed October 17, 2026

This repository collects the deliverables and working artifacts from the Blackbird Australia Software Engineering job simulation — a virtual experience program simulating the work of a software engineer in a start-up environment backed by Blackbird Ventures.

## Project Background

Blackbird Ventures is an Australian venture capital firm; this program places the participant in simulated engineering scenarios drawn from a start-up environment and Blackbird's portfolio ecosystem (including a Harrison.ai codebase simulation). Work completed covers the following areas:

- **Repository & PR workflow** — bootstrapping a React app, publishing via GitHub CLI, and shipping a change through a branch → PR → merge lifecycle
- **Feature code & verification** — implementing and unit-testing login validation logic on a simulated Harrison.ai codebase
- **Product experimentation** — proposing an A/B test on the onboarding funnel
- **Embedded / IoT design** — an Arduino temperature-warning system, designed and simulated on Wokwi
- Sprint retrospectives were also completed on-platform with a hypothetical project team (no repo artifact)

Key artifacts:

- The full git/GitHub CLI command history for the repo workflow task can be found in [command.sh](blackbird_react_Task/command.sh)
- The A/B test experiment proposal can be found in [AB_Test_Proposal.md](AB_Test_task/AB_Test_Proposal.md) (deliverable: [Experiment Proposal_OnboardingFunnel_Solis.docx](<AB_Test_task/Experiment Proposal_OnboardingFunnel_Solis.docx>))
- The Arduino simulation can be explored interactively at [wokwi.com/projects/478137996920966145](https://wokwi.com/projects/478137996920966145)
- The Harrison.ai task submission package can be found at [jonSolis-blackbirdSimulation.zip](blackbird-harrison-ai/jonSolis-blackbirdSimulation.zip)

## Repository Structure

The repository's main structure consists of four task folders, each holding a self-contained deliverable for one activity in the program:

- **blackbird_react_Task/** — Create React App project; logo/link update shipped via PR workflow
- **blackbird-harrison-ai/** — React 17 + MUI login-page simulation; validation logic and tests (work originally done on branch `JonSolis` of `Alexander040105/blackbird-harrison-ai`, upstream `juliusarden/blackbird-harrison-ai`; source vendored here alongside the submission zip)
- **AB_Test_task/** — A/B test experiment proposal (markdown source + Word deliverable + blank template)
- **blackbird_arduino_task_solis/** — Arduino sketch + Wokwi circuit diagram for the temperature warning system

```
BlackBird-Forage-SoftwareEngineering/
├── AB_Test_task/
│   ├── AB_Test_Proposal.md                                  # experiment proposal (source)
│   ├── BTest_Template.md                                    # blank proposal template
│   └── Experiment Proposal_OnboardingFunnel_Solis.docx      # submitted deliverable
├── blackbird-harrison-ai/                                   # "login-page" app (vendored; history lives on fork repo)
│   ├── src/components/LoginForm/                            # validateEmail/validatePassword + unit tests
│   ├── public/
│   ├── jonSolis-blackbirdSimulation.zip                     # original submission package
│   ├── package.json                                         # React 17, MUI, email-validator
│   └── README.md                                            # npm install / start / test
├── blackbird_arduino_task_solis/
│   ├── ntc-basic.ino                                        # NTC thermistor → 3-LED warning sketch
│   ├── diagram.json                                         # Wokwi circuit layout
│   └── wokwi-project.txt                                    # simulator link
├── blackbird_react_Task/
│   ├── command.sh                                           # git/gh CLI command history
│   ├── src/App.js                                           # Propeller Aero logo + link change
│   └── ...                                                  # standard create-react-app project
└── README.md
```

## Executive Summary

### Overview of Findings

Across the four activities, the program exercised the breadth of a start-up engineer's job: shipping changes through a real git/GitHub PR workflow, writing and verifying feature code with tests, thinking like a product manager through a formal experiment proposal, and reaching down the stack into embedded hardware. Each activity produced a verifiable artifact — a merged pull request, a tested validation module, a written experiment proposal, and a runnable circuit simulation.

[Screenshot: collage of the React app, proposal docx, and Wokwi simulation]

## Insights Deep Dive

### Task 1 — React App & PR Workflow (`blackbird_react_Task/`)

- Bootstrapped a React app with `create-react-app`, initialized git, and published the repository publicly via `gh repo create`.
- Created the `update_logo` branch, replaced the default logo with the Propeller Aero CDN asset and the link with `propelleraero.com/dirtmate` in [src/App.js](blackbird_react_Task/src/App.js), then opened and merged PR #1 into `main` — entirely via the GitHub CLI.
- The complete command sequence is documented in [command.sh](blackbird_react_Task/command.sh) for reproducibility.
- Run locally: `cd blackbird_react_Task && npm install && npm start`

[Screenshot: React app rendering the Propeller Aero logo]

### Task 2 — Harrison.ai Login Validation (`blackbird-harrison-ai/`)

- Simulated a Harrison.ai front-end codebase ("login-page") — a React 17 + Material-UI login form.
- Implemented `validateEmail` (via `email-validator`) and `validatePassword`, enforcing a real-world password policy: minimum 8 characters, at least one uppercase and one lowercase letter, one digit, and one special character.
- Wired validation into the `LoginForm` submit handler with inline field errors and a success snackbar; coverage provided by `validateForm.test.js` and `LoginForm.test.js`.
- Work was done on branch `JonSolis` of the fork `Alexander040105/blackbird-harrison-ai` (upstream `juliusarden/blackbird-harrison-ai`); the graded submission is packaged as [jonSolis-blackbirdSimulation.zip](blackbird-harrison-ai/jonSolis-blackbirdSimulation.zip), with the same sources vendored directly in this folder.
- Run locally: `cd blackbird-harrison-ai && npm install && npm test` (then `npm start`)

[Screenshot: login form with validation error states]

### Task 3 — A/B Test Experiment Proposal (`AB_Test_task/`)

- Proposed "Snap & Style," an experiment on Step 3 of the onboarding funnel ("Make your profile personal") targeting the program goal: users who upload profile pictures engage significantly more.
- Variant design: adds a **Take a photo** option (mobile native camera via the `capture` attribute, desktop webcam via `getUserMedia`) and **surfaces photo filters/effects at capture time** — they currently exist only as post-upload editor tabs.
- Measurement plan: primary metric is photo-upload completion rate (photo saved ÷ reached step 3) with a +15% relative lift target; secondary and guardrail metrics (permission-denial rate, abandonment, moderation rejects) plus a full event-tracking spec; 95% confidence / 80% power, 50/50 split.
- Hypothesis grounded in cited external data: LinkedIn's profile-photo engagement stats, the ICWSM/Flickr study on filtered-photo engagement (+21% views, +45% comments), and the Inner Circle onboarding funnel case study.
- Deliverable: [Experiment Proposal_OnboardingFunnel_Solis.docx](<AB_Test_task/Experiment Proposal_OnboardingFunnel_Solis.docx>)

[Screenshot: proposal document, Variations Design section]

### Task 4 — IoT Temperature Warning System (`blackbird_arduino_task_solis/`)

- `ntc-basic.ino` reads a 10K NTC thermistor on analog pin A0 and converts resistance to Celsius via the Beta-parameter equation (BETA = 3950).
- Three-level visual warning: green LED below 30 °C, yellow for 30–80 °C, red above 80 °C (pins 9/8/10), with temperature streamed over serial at 9600 baud.
- `diagram.json` defines the simulated circuit: Arduino Uno + half breadboard, NTC sensor, and three LEDs with 1 kΩ current-limiting resistors.
- Fully simulated — try it at [wokwi.com/projects/478137996920966145](https://wokwi.com/projects/478137996920966145)

[Screenshot: Wokwi simulation with lit LED]

## Recommendations

Based on the work above, the following improvements are noted for future iterations:

- **Arduino sketch (`ntc-basic.ino`):** LEDs are only ever written `HIGH` and never cleared, so they latch on cumulatively as temperature rises — each loop should explicitly write all three outputs (`HIGH` for the active band, `LOW` otherwise). Related: the band check `celsius < 30 || celsius <= 80` works today only by accident of the `else if` ordering; it should read `celsius >= 30 && celsius <= 80`.
- **`command.sh` completeness:** the file currently documents only the branch/commit/push/PR steps — consider restoring the full history (`npx create-react-app`, `gh repo create`, `gh pr merge`) so it covers steps 1–8 as the task requires.
- **`blackbird-harrison-ai` provenance:** the folder has been flattened into normal tracked files (the submission zip extracted beside it); its commit history remains on the fork repo — keep this repo's vendored copy in sync if that codebase evolves further.
- **Duplicate docs:** `blackbird_react_Task/README.md` and `blackbird-harrison-ai/README.md` still contain the stock create-react-app boilerplate — consider trimming them to a short "how to run" note each so the sub-READMEs don't compete with this top-level one.

## Assumptions and Caveats

Throughout the program, the following assumptions and limitations apply:

- The Arduino system was validated in the Wokwi simulator only — behavior on physical hardware (sensor tolerances, real thermistor beta value) is unverified.
- The A/B proposal's +15% lift target is a hypothesized minimum detectable effect; no experiment was actually run and no real funnel data exists behind the proposal.
- `blackbird-harrison-ai` was vendored into this repository after the fact — its git history lives on `Alexander040105/blackbird-harrison-ai` (fork of `juliusarden/blackbird-harrison-ai`), not here.
- The sprint retrospective activity was completed on the Forage platform and has no file artifact in this repository.
