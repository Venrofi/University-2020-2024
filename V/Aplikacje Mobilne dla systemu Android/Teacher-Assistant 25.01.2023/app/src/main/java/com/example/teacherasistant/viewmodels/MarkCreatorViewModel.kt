package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.database.entities.Mark
import com.example.teacherasistant.repositories.MarkRepository
import kotlinx.coroutines.launch

class MarkCreatorViewModel(private val _context: Context, subjectId: Long, studentId: Long) :
    ViewModel() {
    private val _markRepository =
        MarkRepository(AppDatabase.getInstance(_context).markDao(), subjectId, studentId)

    fun insertMark(mark: Mark) = viewModelScope.launch {
        _markRepository.insertMark(mark)
    }
}