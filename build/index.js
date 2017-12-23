window.addEventListener('DOMContentLoaded', function() {
    /**
     * How to read string from C code
     * @link https://wasdk.github.io/WasmFiddle//?b85a7
     */
    setTimeout(() => {
        var buffer = new Uint8Array(
            Module.buffer,
            Module.asm._getMessageRef(),
            Module.asm._getMessageLength() - 1
        );
        var str = '';
        for (var i=0; i<buffer.length; i++) {
            str += String.fromCharCode(buffer[i]);
        }
        console.log(str);
    }, 100);
});