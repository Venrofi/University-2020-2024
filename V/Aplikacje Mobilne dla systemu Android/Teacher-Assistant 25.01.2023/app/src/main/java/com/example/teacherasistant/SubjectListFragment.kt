package com.example.teacherasistant

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import androidx.navigation.findNavController
import androidx.recyclerview.widget.RecyclerView
import com.example.teacherasistant.callback.FragmentCallback
import com.example.teacherasistant.viewmodels.SubjectListViewModel

/**
 * A simple [Fragment] subclass.
 */
class SubjectListFragment : Fragment() {
    private lateinit var _subjectListViewModel: SubjectListViewModel
    private lateinit var _subjectListAdapter: SubjectListAdapter

    private var callback: FragmentCallback? = null

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_subject_list, container, false)

        val subjectListRecyclerView: RecyclerView =
            view.findViewById(R.id.subject_list_recycler_view)

        _subjectListViewModel = SubjectListViewModel(activity as Context)
        _subjectListViewModel.subjects.observe(viewLifecycleOwner) {
            _subjectListAdapter = SubjectListAdapter(it, activity as Context, _subjectListViewModel)
            subjectListRecyclerView.adapter = _subjectListAdapter
        }

        val addSubjectButton: Button = view.findViewById(R.id.add_subject_button)
        addSubjectButton.setOnClickListener {
            val action =
                SubjectListFragmentDirections.actionSubjectListFragmentToSubjectCreatorFragment()

            view.findNavController().navigate(action)
        }

        return view
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        if (callback != null) {
            changeText("Lista przedmiotów")
        }
    }

    override fun onAttach(context: Context) {
        super.onAttach(context)
        callback = context as FragmentCallback
    }

    override fun onDetach() {
        super.onDetach()
        callback = null
    }

    fun changeText(text: String) {
        callback?.onFragmentChanged(text)
    }
}