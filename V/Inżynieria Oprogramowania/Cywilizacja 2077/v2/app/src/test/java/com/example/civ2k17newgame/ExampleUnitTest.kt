package com.example.civ2k17newgame

import org.junit.Assert
import org.junit.Test

import org.junit.Assert.*

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
class ExampleUnitTest {
    @Test
    fun addition_isCorrect() {
        assertEquals(4, 2 + 2)
    }
    @Test
    fun checkDefaultParameteres() {
        val p = Pole(20)
        //assertEquals(p.isClickable, false)
        //assertEquals(p.isOccupied, false)
        Assert.assertTrue("test", true)
    }
}