#include "state_screensaver.h"

#include "receiver.h"
#include "channels.h"
#include "buttons.h"
#include "state.h"
#include "ui.h"


static const unsigned char logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
    0xFF, 0xFF, 0xFB, 0xF8, 0x0F, 0xDF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFB, 0xFC, 0x1F, 0xDF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF9, 0xFC, 0x1F, 0xDF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF9, 0xFE, 0x3F, 0x9F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0xFE, 0x3F, 0x9F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0xFF, 0x7F, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFC, 0x03, 0xF8, 0x7F, 0x7F, 0x1F, 0x80, 0x00, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x03, 0xF8, 0x7F, 0xFE, 0x1F, 0x80, 0x00, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x03, 0xF8, 0x3F, 0xFE, 0x1F, 0x80, 0x00, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x03, 0xF8, 0x3F, 0xFC, 0x1F, 0x80, 0x00, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x03, 0xF8, 0x1F, 0xFC, 0x1F, 0x80, 0x00, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x03, 0xF8, 0x1F, 0xF8, 0x1F, 0x80, 0x00, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFF, 0xFF, 0xF8, 0x0F, 0xF8, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xF0, 0x0F, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0x0F, 0xF0, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xF0, 0x0F, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0x07, 0xF0, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xF0, 0x0F, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0x07, 0xF0, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xF0, 0x0F, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0x0F, 0xF0, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xF0, 0x0F, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF8, 0x0F, 0xF8, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xF0, 0x0F, 0xDF, 0xFF, 0xFF,
    0xFD, 0xFE, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x3F, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0xFE, 0x00, 0x1F, 0xFC, 0x00, 0x00, 0x3F, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x7F, 0x00, 0x3F, 0xFC, 0x00, 0x00, 0x3F, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x7F, 0x00, 0x3F, 0xFE, 0x00, 0x00, 0x3F, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x3F, 0x80, 0x7E, 0x7E, 0x00, 0x00, 0x3F, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x3F, 0xC0, 0x7E, 0x7E, 0x00, 0x00, 0x3F, 0x7F, 0x01, 0xFB, 0xF0, 0x0F, 0xDF, 0xC0, 0x3F,
    0xFC, 0x1F, 0xC0, 0xFE, 0x7F, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFC, 0x0F, 0xE0, 0xFE, 0x7F, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFC, 0x0F, 0xE1, 0xFC, 0x3F, 0x9F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFC, 0x07, 0xF1, 0xFC, 0x3F, 0x9F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFC, 0x07, 0xF3, 0xF8, 0x1F, 0xDF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFC, 0x03, 0xFB, 0xF8, 0x1F, 0xDF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFB, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void StateMachine::ScreensaverStateHandler::onEnter() {
    showLogo = false;
}

void StateMachine::ScreensaverStateHandler::onUpdate() {
    if (this->displaySwapTimer.hasTicked()) {
        this->displaySwapTimer.reset();
 //       showLogo = !showLogo;

        Ui::needUpdate();
    }
}


void StateMachine::ScreensaverStateHandler::onButtonChange(
    Button button,
    Buttons::PressType pressType
) {
    StateMachine::switchState(StateMachine::lastState);
}


void StateMachine::ScreensaverStateHandler::onInitialDraw() {
    Ui::clear();

    if (showLogo) {
        Ui::display.drawBitmap(
            0,
            0,
            logo,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            WHITE
        );
    } else {
        Ui::display.setTextColor(WHITE);

        Ui::display.setTextSize(6);
        Ui::display.setCursor(
            SCREEN_WIDTH_MID - ((CHAR_WIDTH) * 6) / 2 * 2 - 3,
            2);

        Ui::display.print(Channels::getName(Receiver::activeChannel));

        Ui::display.setTextSize(2);
        Ui::display.setCursor(
            SCREEN_WIDTH_MID - ((CHAR_WIDTH + 1) * 2) / 2 * 4 - 1,
            SCREEN_HEIGHT - CHAR_HEIGHT * 2 - 2);
        Ui::display.print(Channels::getFrequency(Receiver::activeChannel));
    }

    Ui::needDisplay();
}

void StateMachine::ScreensaverStateHandler::onUpdateDraw() {
    this->onInitialDraw();
}
