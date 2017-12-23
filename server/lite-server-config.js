module.exports = {
    port: 3000,
    files: [
        './build/**/*.{html,htm,css,js,wasm}',
    ],
    server: {
        baseDir: './build',
    },
    open: false,
}
