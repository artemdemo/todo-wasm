window.addEventListener('DOMContentLoaded', function() {
    setTimeout(() => {
        Module.ccall(
            '_addToDo',
            'number',
            ['string', 'boolean'],
            ['some title', true]
        )
        console.log(Module.Pointer_stringify(Module.asm.__getToDo(0)));
    }, 100);
});