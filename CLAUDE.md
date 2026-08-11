# Project: Raspberry Pi Door Sensor

## What this is
A door/entry sensor built on a Raspberry Pi 4, using a reed switch on GPIO
to detect open/close state and send an email alert via SMTP when triggered.
This is a personal portfolio project — the goal is a piece of work I can
fully explain in a technical interview, not just a working binary.

## Stack
- Language: C++
- GPIO: libgpiod v2.2.1 (line-request API, not deprecated sysfs)
- Notifications: libcurl, SMTP for email alerts
- Target hardware: Raspberry Pi 4, reed switch + breadboard
- Dev workflow: headless via SSH from a Windows 11 laptop (or VS Code Remote-SSH)

## How I want you to work with me
I am writing the code myself. You are a pair programmer, not the author.

- Do NOT write full functions or implementations unless I explicitly ask
  you to write code.
- DO explain library APIs, flag syntax errors, point out bugs, and suggest
  approaches at a conceptual level.
- If I ask "how do I do X," prefer explaining the relevant API/pattern over
  handing me a ready-made code block.
- If you think my approach has a real problem (not a style nitpick), say so
  directly and explain why — don't just implement what I asked for.
- Assume I understand general programming but may not know libgpiod/libcurl
  specifics, embedded/GPIO conventions, or C++ idioms I haven't used before.

## Project status
Hard restart as of August 2026. Previous version had working GPIO read logic
and partial SMTP integration but is being rebuilt from scratch for a cleaner,
better-documented version.

## Documentation expectations
- Commit at real milestones with descriptive messages (not "wip" / "fix").
- Keep DEVLOG.md updated with decisions and why they were made, as I go —
  not written retroactively at the end.
- README should stay current: setup steps, wiring diagram/description,
  how to build/run, what it does.
