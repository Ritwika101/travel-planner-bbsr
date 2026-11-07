# Bhubaneswar Travel Planner — Original C++ on GitHub Pages

A simple, browser-based route planner, powered by the **original C++ `TravelPlanner` class** compiled to WebAssembly. The original adjacency list, `std::priority_queue`, Singleton pattern, Dijkstra routing logic and 21 directed weighted edges are retained.

## Exactly what changed

- `cpp/client.cpp`: **one spelling correction**: `Cavese` → `Caves`.
- `cpp/travelplanner.cpp` and `cpp/travelplanner.hpp`: **unchanged byte-for-byte** from the supplied original project.
- `cpp/web_bridge.cpp`: **new separate adapter**. It calls the original `client.cpp` initializer and original class's `shortestPathWithMinimumStops()`, captures its existing console output, and exposes it to the browser. Does **not** reimplement shortest paths.
- `site/index.html`: UI and graphical display. JavaScript parses C++ output; it does **not** calculate routes.
- `.github/workflows/deploy.yml`: compiles original sources with Emscripten and deploys the static output to GitHub Pages.

## Deploy via GitHub (no local compiler needed)

1. Create a **public** GitHub repository and upload **the contents of this folder**, including the hidden `.github` directory. Upload the files/folders, *not* the ZIP file itself. Use branch `main`.
2. Go to **Settings → Pages → Build and deployment** and choose **GitHub Actions** as the source.
3. Open **Actions** and watch **Compile original C++ and deploy GitHub Pages**. The workflow builds `travelplanner.js` and `travelplanner.wasm` on GitHub and deploys them with the HTML site.
4. When deployment finishes, visit `https://YOUR-USERNAME.github.io/YOUR-REPO/`.

**Do not select “Deploy from a branch”**: this version needs GitHub Actions to compile the C++ source before publishing. The compiled output is still a purely static GitHub Pages site (no server or billable backend).

## Run/build locally (optional)

Install [Emscripten](https://emscripten.org/docs/getting_started/downloads.html), then run:

```bash
bash build.sh
python3 -m http.server 8000 --directory site
```

Open http://localhost:8000 in a browser. Opening `index.html` directly with `file://` won't load WebAssembly.

## Important notes

- Routes and distances are from the supplied **directed project graph**, *not* a live road navigation service.
- `travelplanner.cpp` contains existing compiler narrowing warnings; these were left unchanged as requested.
- The new web bridge only handles initialization and output capture, not route computation.
- The source logic was tested locally with a native C++ compiler. Actual WebAssembly compilation is performed by GitHub Actions because Emscripten is unavailable in the current build environment.
