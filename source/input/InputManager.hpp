#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

/**
 * Interface for abstracting user input.
 */
class InputManager
{
public:
    virtual ~InputManager() {}

    /**
     * Check if the user requested to close/kill the program.
     */
    virtual bool shutdownReceived() const =0;

    /**
     * Update the input system's state.
     */
    virtual void update()=0;
};

#endif // INPUTMANAGER_HPP
