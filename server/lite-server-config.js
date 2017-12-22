module.exports = {
    open: false,
    port: 3000,
    files: ["./build/**/*.{html,htm,css,js,wasm}"],
    server: {
        baseDir: "./build"
    }
}