# Bhubaneswar Travel Planner

An interactive travel planner for exploring attractions in Bhubaneswar, Odisha. Choose a starting location and destination to find the shortest route through a weighted graph of local landmarks.

The application runs a **C++ routing engine compiled to WebAssembly** directly in the browser and can be hosted as a static site on GitHub Pages.

## Features

- Select a source and destination from 11 Bhubaneswar landmarks.
- Find the shortest route using Dijkstra's algorithm, with fewer intermediate stops preferred when total distances are equal.
- View the route, total distance, and number of intermediate stops.
- Explore a schematic SVG graph of 21 directed, weighted connections, with the selected path highlighted.
- Use the application on desktop or mobile without signing in or connecting to a backend.

## Technology

- **C++:** Graph representation using adjacency lists, a priority queue, and a Singleton `TravelPlanner` class.
- **WebAssembly (Emscripten):** Runs the routing engine in the browser.
- **HTML, CSS, JavaScript, and SVG:** User interface and graph visualization.
- **GitHub Pages and GitHub Actions:** Static hosting and automated builds.

## Project structure

```text
├── cpp/
│   ├── client.cpp
│   ├── travelplanner.cpp
│   ├── travelplanner.hpp
│   └── web_bridge.cpp
├── site/
│   ├── index.html
│   └── favicon.svg
├── .github/workflows/deploy.yml
├── build.sh
└── README.md
```

## Run locally

Install [Emscripten](https://emscripten.org/docs/getting_started/downloads.html) and activate its environment. From the project directory, run:

```bash
bash build.sh
python3 -m http.server 8000 --directory site
```

Open **http://localhost:8000** in your browser. Run the app through a local web server rather than opening `index.html` directly.

## Author

**Ritwika Pal**