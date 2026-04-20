# Docs Checklist (Car Firmware)

Use this folder to make the repository presentation recruiter-friendly.

## Recommended Media

Add these files under `docs/media/`:

- `demo-drive.gif` - short loop of steering + throttle response
- `demo-distance.mp4` - distance telemetry update demo
- `wiring-top.jpg` - top-view wiring photo
- `wiring-labels.jpg` - labeled wiring photo
- `block-diagram.png` - high-level system block diagram

## Suggested Captions

- What hardware is shown
- What the UART packet stream is doing in this scene
- What safety/failsafe behavior is demonstrated

## Embed Example for README

```md
## Demo

![Drive Demo](docs/media/demo-drive.gif)

[Distance Telemetry Video](docs/media/demo-distance.mp4)
```

## Quality Bar Before Posting

- Media filenames are clean and descriptive
- Wires are labeled in at least one image
- One architecture image exists (`block-diagram.png`)
- README demo links resolve and render on GitHub
