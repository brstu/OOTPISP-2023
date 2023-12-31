#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

class List {
public:
    virtual void render() const = 0;
    virtual List* clone() = 0;
    virtual ~List() {}
};

class InputField {
public:
    virtual void render() const = 0;
    virtual InputField* clone() = 0;
    virtual ~InputField() {}
};

class Button {
public:
    virtual void render() const = 0;
    virtual Button* clone() = 0;
    virtual ~Button() {}
};

class Language {
public:
    virtual void display() const = 0;
    virtual Language* clone() = 0;
    virtual ~Language() {}
};


class PlannerAppList : public List {
public:
    void render() const override {
        std::cout << "Planner app list rendered." << std::endl;
    }

    List* clone() override {
        return new PlannerAppList();
    }
};

class PlannerAppInputField : public InputField {
public:
    void render() const override {
        std::cout << "Planner app input field rendered." << std::endl;
    }

    InputField* clone() override {
        return new PlannerAppInputField();
    }
};

class PlannerAppButton : public Button {
public:
    void render() const override {
        std::cout << "Planner app button rendered." << std::endl;
    }

    Button* clone() override {
        return new PlannerAppButton();
    }
};

class PlannerAppLanguage : public Language {
public:
    void display() const override {
        std::cout << "Planner app language rendered." << std::endl;
    }

    Language* clone() override {
        return new PlannerAppLanguage();
    }
};


class AbstractFactory {
public:
    virtual List* createList() const = 0;
    virtual InputField* createInputField() const = 0;
    virtual Button* createButton() const = 0;
    virtual Language* createLanguage() const = 0;
    virtual ~AbstractFactory() {}
};

class AbstractPrototypeFactory : public AbstractFactory {
public:
    AbstractPrototypeFactory(List* ls,  InputField* ifl, Button* btn, Language* lng) {
        listPrototype = ls;
        inputFieldPrototype = ifl;
        buttonPrototype = btn;
        languagePrototype = lng;
    }

    virtual ~AbstractPrototypeFactory() {
        delete listPrototype;
        delete inputFieldPrototype;
        delete buttonPrototype;
        delete languagePrototype;
    }

    List* createList() const override {
        return listPrototype->clone();
    }

    InputField* createInputField() const override {
        return inputFieldPrototype->clone();
    }

    Button* createButton() const override {
        return buttonPrototype->clone();
    }

    Language* createLanguage() const override {
        return languagePrototype->clone();
    }
private:
    List* listPrototype;
    InputField* inputFieldPrototype;
    Button* buttonPrototype;
    Language* languagePrototype;
};


class PlannerAppFactory : public AbstractFactory {
public:
    List* createList() const override {
        return new PlannerAppList();
    }

    InputField* createInputField() const override {
        return new PlannerAppInputField();
    }

    Button* createButton() const override {
        return new PlannerAppButton();
    }

    Language* createLanguage() const override {
        return new PlannerAppLanguage();
    }
};


class SingletonPlannerAppFactory : public AbstractFactory {
private:
    SingletonPlannerAppFactory() {}
    static SingletonPlannerAppFactory* instance;

public:
    static SingletonPlannerAppFactory* getInstance() {
        if (instance == nullptr) {
            instance = new SingletonPlannerAppFactory();
        }
        return instance;
    }

    List* createList() const override {
        return new PlannerAppList();
    }

    InputField* createInputField() const override {
        return new PlannerAppInputField();
    }

    Button* createButton() const override {
        return new PlannerAppButton();
    }

    Language* createLanguage() const override {
        return new PlannerAppLanguage();
    }
};

SingletonPlannerAppFactory* SingletonPlannerAppFactory::instance = nullptr;

#endif // ABSTRACTFACTORY_H
