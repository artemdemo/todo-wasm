const toDoModel = {
    addToDo: null,
    getToDo: null,
    deleteToDo: null,
    getLength: null,
};

const onInit = () => {
    toDoModel.addToDo = Module.cwrap(
        '_addToDo',
        'number',
        ['string', 'boolean']
    )
    toDoModel.getToDo = (todoId) => {
        const todoPointer = Module.asm.__getToDo(todoId);
        const todoString = Module.Pointer_stringify(todoPointer);
        let todo = null;
        try {
            todo = JSON.parse(todoString);
        } catch(e) {}
        return todo;
    };
    toDoModel.getLength = () => Module.asm.__getToDoListLength();
    
    toDoModel.addToDo('Some title', false);
    console.log(toDoModel.getToDo(0));
    console.log(toDoModel.getToDo(1));
};

window.addEventListener('DOMContentLoaded', function() {
    /**
     * `Module.onRuntimeInitialized`
     * If set, this function is called when the runtime is fully initialized,
     * that is, when compiled code is safe to run.
     * @link https://kripken.github.io/emscripten-site/docs/api_reference/module.html#Module.onRuntimeInitialized
     */
    Module.onRuntimeInitialized = onInit;
});
